# RT-Thread 上下文切换 Bug 调试记录：`texit` 函数指针被 trap 帧覆盖

## 一、背景：RT-Thread 线程创建与上下文切换

RT-Thread 需要通过 CTE（Common Trap Entry）机制在 NEMU 上实现线程的创建和切换。涉及的关键函数：

| 函数 | 作用 |
|------|------|
| `rt_hw_stack_init` | 为新线程构造初始栈和上下文 |
| `thread_init_wrapper` | 包裹函数：先调用 `tentry`，再调用 `texit` |
| `kcontext` | 在栈上构造一个 `Context` 结构体，模拟"被中断"的状态 |
| `ev_handler` | yield 时保存/切换上下文 |
| `__am_asm_trap` | trap 入口，保存/恢复 144 字节的 Context 帧 |

## 二、Bug 的本质：`struct thread_init_args` 被 trap 帧覆盖

### 2.1 栈布局是如何构造的

`rt_hw_stack_init` 在栈上布置了两个东西：

```c
// context.c
uintptr_t args_addr = (uintptr_t)(stack_addr - sizeof(Context) - sizeof(struct thread_init_args));
```

```
高地址 (stack_addr = 栈顶)
          ← 初始 sp（mret 之后）
┌─────────────────────────┐
│    Context (144 字节)     │  kcontext 创建
│  gpr[0..31] mcause       │
│  mstatus mepc pdir       │
├─────────────────────────┤ ← stack_addr - 144
│  thread_init_args (12B)  │  args 结构体
│  tentry (4B)             │  offset +0
│  parameter (4B)          │  offset +4
│  texit (4B)              │  offset +8
└─────────────────────────┘ ← stack_addr - 156
低地址
```

这个布局本身没有问题——`args` 紧贴在 `Context` 下方，`kcontext` 返回的指针指向 Context 区域，线程启动后 sp 被设为 `stack_addr`，一切正常。

### 2.2 线程启动流程

1. 调度器调用 `rt_hw_context_switch_to(&thread->sp)`
2. 触发 `yield()` → `ecall` → 进入 `__am_asm_trap`
3. trap handler 恢复目标线程的 Context：sp 被设为 `stack_addr`，pc 跳到 `thread_init_wrapper`
4. `mret` 返回，线程开始执行，`a0 = args` 指针

### 2.3 致命时刻：`tentry` 内部发生 yield

`thread_init_wrapper` 运行起来后，调用 `tentry(parameter)`。在 `tentry` 执行过程中，线程很可能被调度切换出去（比如调用 `rt_thread_delay`、时间片用完等），这时会触发 `yield()`。

yield 时，`__am_asm_trap` 做的第一件事：

```asm
# trap.S
addi sp, sp, -CONTEXT_SIZE   # sp -= 144，在当前 sp 下方开辟 144 字节
MAP(REGS, PUSH)               # 把所有 32 个寄存器存进去
```

此时 sp 大约在 `stack_addr - 64` ~ `stack_addr - 100` 之间（经历了 `thread_init_wrapper` 的函数序言、`printf`、`tentry` 等调用），所以 **trap 帧从 `sp - 144` 开始，向上延伸 144 字节到 `sp`**。

用调试数据 `args = 0x800e1578` 来具体计算：

```
args 地址范围:   [0x800e1578, 0x800e1584)  ← 12 字节
Context 范围:    [0x800e1584, 0x800e1614)  ← 144 字节
stack_addr:      0x800e1614               ← 初始 sp

假设 tentry 内部 yield 时 sp ≈ 0x800e15c4（大约下降了 80 字节）：
Trap 帧:         [0x800e1534, 0x800e15c4)  ← 144 字节

                    0x800e1534              0x800e1578     0x800e1584    0x800e15c4
                        |                       |              |             |
                        v                       v              v             v
Trap 帧:  [================================|====|==============|=============|
args:                               [===========]
                                      ↑
                            args 完全被 trap 帧覆盖！
```

trap 帧在保存寄存器时，某个 `gpr[x]` 的存储位置刚好对应 `args.texit` 的地址，于是 `texit` 的值被那个寄存器的值覆盖了。

### 2.4 为什么覆盖后变成了 `.rodata` 地址

trap 帧保存的是 **当时 CPU 各寄存器的值**。其中一个寄存器（计算显示大约是 `gpr[19]` 即 `s3`）的值恰好指向 `.rodata` 段的某个字符串（如 `__fsym_memcheck_name`），这个值被写入到了 `texit` 字段的位置。

所以 `tentry` 返回后，`thread_init_wrapper` 读取 `init_args->texit` 得到的是 `.rodata` 中的地址，`jr a5` 跳转过去执行字符串数据 → crash。

## 三、调试过程复盘

### 第一阶段：现象观察

通过 printf 调试发现了关键线索：

```
[DBG] wrapper: args=0x800e1578, tentry=0x800187d0, texit=0x8001740c   ← 正确
[DBG] wrapper: after tentry, texit=0x8005b1e8                          ← 被篡改！
```

- `texit` 在 `tentry` 调用前是 `0x8001740c`（正确的 `_thread_exit` 地址）
- `tentry` 返回后变成了 `0x8005b1e8`（`.rodata` 段地址）
- 说明 `tentry` 执行期间，栈上的 `args.texit` 被写入了别的数据

### 第二阶段：排除其他可能性

| 排除项 | 方法 | 结论 |
|--------|------|------|
| 栈溢出 | 栈从 8K 增到 32K，问题依旧 | ❌ 不是栈溢出 |
| mepc 恢复出错 | 加范围检查，从未越界 | ❌ trap handler 正确 |
| Context 大小不匹配 | 已修 CONTEXT_SIZE = 144 | ❌ 已修复，不是本次问题 |

### 第三阶段：锁定根因

关键洞察：**`args` 放在哪里？**

`args` 放在 Context 下方（更低地址），也就是栈的最底部。而 trap handler 在 yield 时从当前 `sp` 向下（更低地址）保存 144 字节的上下文帧。

这两者之间的关系：

```
stack_addr ──┐
             │  thread_init_wrapper 的栈帧（局部变量、saved ra/s0）
             │  tentry 的栈帧
   sp_yield ─┤  ← yield 时 sp 在这里
             │  ╔══════════════════════╗
             │  ║   trap 帧 (144B)      ║  ← sp_yield - 144 到 sp_yield
             │  ║   覆盖了 args 区域！   ║
             │  ╚══════════════════════╝
  args_addr ─┤  ← args 在这里（被覆盖）
             │  （未使用的栈空间）
stack_bottom ┘
```

## 四、修复方案

修复非常简单——**在 `tentry` 执行前，把 `args` 的内容拷贝到 `thread_init_wrapper` 自己的局部变量中**：

```c
static void thread_init_wrapper(void *args) {
  struct thread_init_args init_args = *(struct thread_init_args *)args;  // 值拷贝！
  init_args.tentry(init_args.parameter);
  init_args.texit();
}
```

为什么这能工作：

```
stack_addr ──┐
             │  init_args（局部变量拷贝）← 在 wrapper 的栈帧中，地址高
             │  saved s0, ra
             │  tentry 的栈帧
   sp_yield ─┤
             │  trap 帧（向下延伸）
             │  覆盖了原始 args ← 无所谓，已经拷贝过了
  args_addr ─┤
stack_bottom ┘
```

- `init_args` 是 `thread_init_wrapper` 的**局部变量**，分配在 wrapper 的栈帧中（靠近 `stack_addr` 的高地址处）
- 当 yield 触发 trap 时，trap 帧从更低的 `sp` 向下延伸，**不会触及 wrapper 栈帧中的局部变量**
- 即使原始 `args` 被覆盖也无所谓，因为值已经拷贝到了安全的地方

## 五、经验总结

| 教训 | 说明 |
|------|------|
| **不要在"安全区"外放置关键数据** | `args` 放在 Context 下方，属于"迟早会被 trap 帧覆盖"的区域 |
| **trap 帧会覆盖 sp 下方的数据** | `__am_asm_trap` 的 `addi sp, sp, -144` + 寄存器保存会无条件写入 sp 以下 144 字节 |
| **值拷贝是简单有效的防御** | 只需一行 `struct X copy = *ptr`，就把数据移到了当前函数的安全栈帧中 |
| **调试时观察"谁改了我的内存"** | 看到 `texit` 从正确值变成 `.rodata` 地址，应立即问：谁写了这个地址？→ trap 帧的寄存器保存 |
