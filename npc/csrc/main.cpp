#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

#include "Vcustom_cpu.h"
#include "verilated.h"
#include "sdb.h"

// ==================== 内存与MMIO ====================

#define PMEM_START 0x80000000u
#define PMEM_SIZE  (128 * 1024 * 1024)  // 128MB
#define SERIAL_MMIO 0xa00003f8u
#define TIMER_MMIO  0xa0000048u

static uint8_t pmem[PMEM_SIZE];

static inline uint8_t* guest_to_host(uint32_t addr) {
  return &pmem[addr - PMEM_START];
}

static inline bool in_pmem(uint32_t addr) {
  return (addr >= PMEM_START) && (addr < PMEM_START + PMEM_SIZE);
}

// 加载二进制文件到物理内存
extern "C" void load_binary(const char *bin_path) {
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

// ebreak回调: 不再直接exit, 而是设置状态让仿真循环退出
extern "C" void set_ebreak() {
  printf("ebreak: program has finished. SUCCESS\n");
  npc_state.state = NPC_END;
}

// DPI-C内存读
extern "C" int pmem_read(int raddr) {
  uint32_t addr = (uint32_t)(raddr & ~0x3u);

  // 时钟MMIO
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
  }
  else {
    fprintf(stderr, "Invalid memory read at address: 0x%08x\n", addr);
    npc_state.state = NPC_ABORT;
    return 0;
  }
}

// DPI-C内存写
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  uint32_t addr = (uint32_t)(waddr & ~0x3u);

  // 串口MMIO
  if (addr == SERIAL_MMIO) {
    putchar(wdata);
    fflush(stdout);
    return;
  }

  // 普通内存写入
  if (in_pmem(addr)) {
    uint8_t *p = guest_to_host(addr);
    uint8_t *data_bytes = (uint8_t *)&wdata;
    for (int i = 0; i < 4; i++) {
      if (wmask & (1 << i)) {
        p[i] = data_bytes[i];
      }
    }
  }
  else {
    fprintf(stderr, "Invalid memory write at address: 0x%08x\n", addr);
    npc_state.state = NPC_ABORT;
  }
}

// ==================== Verilator仿真引擎 ====================

static Vcustom_cpu *top = NULL;

// 推进一个时钟周期
static void single_cycle() {
  top->clk = 0;
  top->eval();
  top->clk = 1;
  top->eval();
}

// 复位
static void reset(int n) {
  top->rst = 1;
  for (int i = 0; i < n; i++) {
    single_cycle();
  }
  top->rst = 0;
}

// ==================== sdb接口实现 ====================

// 检测是否有指令retire (通过inst_retire信号)
static bool is_inst_retire() {
  // inst_retire[69] 是 inst_wen, 表示有指令写回寄存器
  // 但有些指令不写寄存器, 所以检测PC变化更准确
  static uint32_t last_pc = 0;
  uint32_t cur_pc = (uint32_t)(top->inst_retired & 0xFFFFFFFF);  // PC_WB在低32位
  bool retired = (cur_pc != last_pc) && (cur_pc != 0);
  last_pc = cur_pc;
  return retired;
}

// 执行n条指令 (n=(uint64_t)-1 表示一直运行)
void sim_exec(uint64_t n) {
  npc_state.state = NPC_RUNNING;
  uint64_t count = 0;
  while (n == (uint64_t)-1 || count < n) {
    single_cycle();
    if (is_inst_retire()) {
      count++;
      npc_state.nr_inst++;
    }
    if (npc_state.state != NPC_RUNNING) break;
  }
  if (npc_state.state == NPC_RUNNING) {
    npc_state.state = NPC_STOP;
  }
}

// 读取PC (从if阶段的PC端口)
uint32_t sim_get_pc() {
  return (uint32_t)top->PC;
}

// 打印所有寄存器
void sim_print_regs() {
  // 通过DPI-C读取寄存器: 从pmem中无法直接读regfile
  // 这里通过inst_retire信号间接获取信息
  uint32_t pc = sim_get_pc();
  printf("PC = 0x%08x\n", pc);
  printf("(更多寄存器需要添加DPI-C接口来读取regfile)\n");
}

// 初始化仿真
void sim_init(const char *bin_path) {
  Verilated::mkdir("logs");
  top = new Vcustom_cpu;

  // 加载程序
  load_binary(bin_path);

  // 为指令存储提供初始握手信号 (避免x态)
  top->Inst_Req_Ready = 1;
  top->Inst_Valid = 1;
  top->Mem_Req_Ready = 1;
  top->Read_data = 0;
  top->Read_data_Valid = 0;
  top->intr = 0;

  // 复位
  reset(10);
  printf("Simulation initialized. Binary: %s\n", bin_path);
}

// ==================== main ====================

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  // 检查参数: 需要一个二进制文件路径
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
    return 1;
  }

  // 初始化仿真
  sim_init(argv[1]);

  // 进入sdb主循环
  sdb_mainloop();

  // 清理
  top->final();
  delete top;
  return 0;
}
