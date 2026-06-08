#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

#define ITRACE 1

// Verilator 头文件
#include "Vcustom_cpu.h"
#include "Vcustom_cpu___024root.h"
#include "verilated.h"

// SDB 调试器接口
#include "include/sdb.h"

// 内存配置
#define PMEM_START 0x80000000u
#define PMEM_SIZE  (128 * 1024 * 1024)  // 128MB

// MMIO 地址
#define SERIAL_MMIO 0xa00003f8u
#define TIMER_MMIO  0xa0000048u

// RISC-V 32 寄存器名称
static const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// 物理内存
static uint8_t pmem[PMEM_SIZE];

// 全局仿真顶层指针, 供 DPI-C 回调函数访问 CPU 内部信号
static Vcustom_cpu *g_top = nullptr;

// ebreak 标志, 由 DPI-C set_ebreak() 设置
static bool g_ebreak = false;
static int  g_exit_code = 0;

// ==================== 内存辅助函数 ====================

static inline uint8_t* guest_to_host(uint32_t addr) {
  return &pmem[addr - PMEM_START];
}

static inline bool in_pmem(uint32_t addr) {
  return (addr >= PMEM_START) && (addr < PMEM_START + PMEM_SIZE);
}

// 加载二进制文件到物理内存
static void load_binary(const char *bin_path) {
  FILE *fp = fopen(bin_path, "rb");
  if (!fp) {
    fprintf(stderr, "Cannot open binary file: %s\n", bin_path);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  if (size > PMEM_SIZE) {
    fprintf(stderr, "Binary file too large: %ld bytes\n", size);
    fclose(fp);
    exit(1);
  }

  fread(pmem, 1, size, fp);
  fclose(fp);
  printf("Loaded %ld bytes from %s into pmem\n", size, bin_path);
}

// ==================== DPI-C 回调函数 ====================

// ebreak 回调, 由 wb.v 通过 DPI-C 调用
// 不再直接 exit(), 而是设置标志让 sim_exec 自行处理状态转换
extern "C" void set_ebreak() {
  if (g_ebreak) return;  // 防止重复触发
  int code = g_top ? (int)(uint32_t)g_top->a0_out : 1;
  g_ebreak = true;
  g_exit_code = code;
}

// 从物理地址读取 4 字节, 由 mem.v 通过 DPI-C 调用
// 总是读取地址为 raddr & ~0x3u 的 4 字节并返回
extern "C" int pmem_read(int raddr) {
  uint32_t addr = (uint32_t)(raddr & ~0x3u);

  // 时钟 MMIO: 返回当前时间(微秒)
  if (addr == TIMER_MMIO || addr == TIMER_MMIO + 4) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t us = (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
    if (addr == TIMER_MMIO) {
      return (int)(uint32_t)(us & 0xFFFFFFFF);
    } else {
      return (int)(uint32_t)(us >> 32);
    }
  }

  // 普通内存读取
  if (in_pmem(addr)) {
    return *(int32_t *)guest_to_host(addr);
  } else {
    fprintf(stderr, "Invalid memory read at address: 0x%08x\n", addr);
    exit(1);
  }

  return 0;
}

// 向物理地址写入, 由 mem.v 通过 DPI-C 调用
// 总是往地址为 waddr & ~0x3u 的 4 字节按掩码 wmask 写入 wdata
// wmask 中每比特表示 wdata 中 1 个字节的掩码
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  uint32_t addr = (uint32_t)(waddr & ~0x3u);

  // 串口 MMIO: 输出字符
  if (addr == SERIAL_MMIO) {
    putchar(wdata);
    fflush(stdout);
    return;
  }

  // 普通内存写入, 按字节掩码写入
  if (in_pmem(addr)) {
    uint8_t *p = guest_to_host(addr);
    uint8_t *data_bytes = (uint8_t *)&wdata;
    for (int i = 0; i < 4; i++) {
      if (wmask & (1 << i)) {
        p[i] = data_bytes[i];
      }
    }
  } else {
    fprintf(stderr, "Invalid memory write at address: 0x%08x\n", addr);
    exit(1);
  }
}

// ==================== 仿真控制接口 ====================

// 初始化仿真: 加载二进制, 初始化 Verilator, 复位 CPU
void sim_init(const char *bin_path) {
  load_binary(bin_path);

  g_top = new Vcustom_cpu;

  // 初始化输入信号
  g_top->rst = 1;
  g_top->clk = 0;
  // 取指握手: 内存始终就绪
  g_top->Inst_Req_Ready = 1;
  g_top->Inst_Valid = 1;
  g_top->Instruction = 0;
  // 数据内存握手: 通过 DPI-C 在 mem.v 中直接处理
  g_top->Mem_Req_Ready = 1;
  g_top->Read_data = 0;
  g_top->Read_data_Valid = 0;
  // 中断: cpu-tests 不使用中断
  g_top->intr = 0;
  g_top->eval();

  // 复位若干周期, 确保 IF 阶段 PC 初始化到 0x80000000
  for (int i = 0; i < 10; i++) {
    g_top->clk = 1;
    g_top->eval();
    g_top->clk = 0;
    g_top->eval();
  }

  // 释放复位信号, CPU 开始执行
  g_top->rst = 0;

  npc_state.state = NPC_STOP;
}

// 推进一个时钟周期
// 返回 true 表示本周期有一条指令从 WB 阶段退役
bool sim_clock_step() {
  // 根据 CPU 输出的 PC 从内存中读取指令, 提供给取指接口
  g_top->Instruction = pmem_read(g_top->PC);

  // 上升沿
  g_top->clk = 1;
  g_top->eval();

  // 下降沿: 组合逻辑稳定
  g_top->clk = 0;
  g_top->eval();

  // 通过 Verilator 暴露的内部信号 WB_work 判断本周期是否有指令退役
  // (比 inst_retired[69] 更准确, 后者仅在有寄存器写回时为 1)
  return g_top->rootp->custom_cpu__DOT__WB_EX__DOT__WB_work;
}

// 获取当前 PC
uint32_t sim_get_pc() {
  return g_top ? (uint32_t)g_top->PC : 0;
}

//获取当前指令
uint32_t sim_get_inst() {
  return g_top ? (uint32_t)g_top->Instruction : 0;
}

// 通过 Verilator 暴露的内部信号路径读取寄存器值
// 等效于 DPI-C 方式: Verilator 将 regfile 数组编译为可直接访问的 C 数组
uint32_t sim_get_reg(int idx) {
  if (idx < 0 || idx >= 32 || !g_top) return 0;
  if (idx == 0) return 0;  // x0 始终为 0
  return g_top->rootp->custom_cpu__DOT__ID_EX__DOT__reg_file_ex__DOT__regfile[idx];
}

// 打印所有寄存器和 PC (仿照 NEMU isa_reg_display)
void sim_print_regs() {
  for (int i = 0; i < 32; i++) {
    printf("%-4s = 0x%08x  ", regs[i], sim_get_reg(i));
    if ((i + 1) % 4 == 0) printf("\n");
  }
  printf("pc   = 0x%08x\n", sim_get_pc());
}

// 仿照 NEMU cpu_exec: 执行 n 条指令
// n = -1 (即 UINT64_MAX) 表示持续运行直到 ebreak
void sim_exec(uint64_t n) {
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  const uint64_t MAX_CYCLES = 100000000ULL;  // 安全上限: 1 亿周期
  uint64_t cycle = 0;
  uint64_t inst_cnt = 0;  // 本轮已退役的指令数

  while (cycle < MAX_CYCLES) {
    bool retired = sim_clock_step();
    cycle++;

    if (retired) {
      inst_cnt++;
      npc_state.nr_inst++;
      if(ITRACE){
        printf("0x%08x: Instruction retired, \
              Instruction: %lu\n", sim_get_pc(), sim_get_inst());
      }
    }

    // 检测 ebreak
    if (g_ebreak) {
      npc_state.state = (g_exit_code == 0) ? NPC_END : NPC_ABORT;
      printf("npc: %s at pc = 0x%08x, exit code = %d\n",
             g_exit_code == 0 ? "\33[1;32mHIT GOOD TRAP\33[0m"
                              : "\33[1;31mHIT BAD TRAP\33[0m",
             sim_get_pc(), g_exit_code);
      return;
    }

    // 已执行足够指令数, 暂停
    if (inst_cnt >= n) {
      npc_state.state = NPC_STOP;
      return;
    }
  }

  // 超时
  fprintf(stderr, "Simulation exceeded maximum cycle count (%lu)\n",
          (unsigned long)MAX_CYCLES);
  npc_state.state = NPC_ABORT;
  g_exit_code = 1;
}

// ==================== 主函数 ====================

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <binary> [-i]\n", argv[0]);
    return 1;
  }

  // 解析参数: 默认 batch 模式, 加 -i 进入交互模式
  bool interactive = false;
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0) interactive = true;
  }

  // 初始化 Verilator 命令行参数解析
  Verilated::commandArgs(argc, argv);

  // 初始化仿真环境
  sim_init(argv[1]);

  // 启动 SDB
  if (!interactive) {
    sdb_set_batch_mode();
  }
  sdb_mainloop();

  // 清理: 根据仿真状态决定退出码
  int ret = g_exit_code;   // ebreak 设置的退出码 (0=GOOD TRAP, 非0=BAD TRAP)
  if (npc_state.state == NPC_ABORT) ret = 1;   // 超时等异常终止
  if (npc_state.state == NPC_QUIT)  ret = 1;   // 用户主动退出, 程序尚未结束, 不算 PASS
  delete g_top;
  return ret;
}
