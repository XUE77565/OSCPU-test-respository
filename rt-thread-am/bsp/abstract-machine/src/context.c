#include <am.h>
#include <klib.h>
#include <rtthread.h>

//由于CTE机制，用全局变量进行信息传递
static rt_ubase_t to_switch = 0;
static rt_ubase_t from_switch = 0;

static Context* ev_handler(Event e, Context *c) {
  switch (e.event) {
    case EVENT_YIELD:
      if(from_switch){
        *(Context **)from_switch = c;//保存上下文到switch_from
      }
      if(to_switch){
        c = *(Context **)to_switch;//切换到switch_to指向的上下文
      };
      return c;
    default: printf("Unhandled event ID = %d\n", e.event); assert(0);
  }
  return c;
}

void __am_cte_init() {
  cte_init(ev_handler);
}

//用于切换到to指向的上下文
void rt_hw_context_switch_to(rt_ubase_t to) {
  from_switch = 0;
  to_switch = to;
  yield();//触发切换
}

void rt_hw_context_switch(rt_ubase_t from, rt_ubase_t to) {
  from_switch = from;
  to_switch = to;
  yield();//触发切换
}

void rt_hw_context_switch_interrupt(void *context, rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread) {
  assert(0);
}

//包裹函数，作为kcontext的真正入口
struct thread_init_args {
  void (*tentry)(void *);
  void *parameter;
  void (*texit)(void);
};

//先调用tentry，再调用texit
//注意: args 放在栈底(Context下方), 当 tentry 内部触发 yield 时,
//      trap handler 会在 sp-144 处保存上下文帧, 会覆盖 args 区域.
//      所以必须先把 args 拷贝到局部变量(在 wrapper 自己的栈帧中, 地址更高, 不会被覆盖).
static void thread_init_wrapper(void *args) {
  //原本 struct thread_init_args *init_args = (struct thread_init_args *)args;
  //这个是指针，所以被复写之后会出现问题
  struct thread_init_args init_args = *(struct thread_init_args *)args;
  init_args.tentry(init_args.parameter);
  init_args.texit();
}

//创建上下文
rt_uint8_t *rt_hw_stack_init(void *tentry, void *parameter, rt_uint8_t *stack_addr, void *texit) {
  //对齐栈地址
  stack_addr = (rt_uint8_t *)((uintptr_t)stack_addr & (0xFFFFFFFC));
  //计算地址
  uintptr_t args_addr = (uintptr_t)(stack_addr - sizeof(Context) - sizeof(struct thread_init_args));
  //创建args
  struct thread_init_args *args = (struct thread_init_args *)args_addr;
  args->tentry = (void (*)(void *))tentry;//tentry是线程入口函数，有参数parameter
  args->parameter = parameter;
  args->texit = (void (*)(void))texit;//texit是线程退出函数，无参数
  //构造上下文，开辟出空间
  Area kstack;
  kstack.start = (void *)args_addr;
  kstack.end = (void *)stack_addr;
  //调用包裹函数
  return (rt_uint8_t *)kcontext(kstack, thread_init_wrapper, (void *)args);
}
