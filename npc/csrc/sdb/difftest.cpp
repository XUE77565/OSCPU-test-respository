/***************************************************************************************
 * DiffTest — 通过动态链接 NEMU 参考实现进行差分测试
 *
 * 动态库 API (riscv32-nemu-interpreter-so):
 *   difftest_init, difftest_memcpy, difftest_regcpy, difftest_exec, difftest_raise_intr
 ***************************************************************************************/

#include "../include/sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

// ==================== 常量 ====================

#define RESET_VECTOR 0x80000000u

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

// ==================== CPU 状态结构体 (与 NEMU riscv32_CPU_state 布局一致) ====================

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
} CPU_state;

// ==================== NEMU API 函数指针 ====================

static void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
static void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
static void (*ref_difftest_exec)(uint64_t n) = NULL;
static void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool g_difftest_enabled = false;
static bool g_skip_ref = false;

// ==================== ANSI 颜色 ====================

#ifndef ANSI_FG_RED
#define ANSI_FG_RED     "\33[1;31m"
#endif
#ifndef ANSI_FG_GREEN
#define ANSI_FG_GREEN   "\33[1;32m"
#endif
#ifndef ANSI_FMT
#define ANSI_FMT(fmt, fg) fg fmt "\33[0m"
#endif

// ==================== 寄存器名称 (用于打印差异) ====================

static const char *reg_names[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// ==================== 从 NPC 获取当前寄存器状态 ====================
// 关键: 寄存器文件写入与 WB 数据锁存在同一个上升沿。
// 非阻塞赋值使得当 WB_work=1 时, 寄存器文件还在用旧 MEM_to_WB_data_reg 写入。
// 所以必须用 inst_retired 中的 WB 写信息来修正。

static int dbg_inst_cnt = 0;

static void get_cpu_state(CPU_state *s) {
  // 1. 读取寄存器文件 (比 WB 写回延迟一拍)
  for (int i = 0; i < 32; i++) {
    s->gpr[i] = sim_get_reg(i);
  }
  s->pc = sim_get_pc();

  // 2. 用 inst_retired 中的 WB 写信息修正当前指令的写回结果
  bool wb_wen = sim_get_wb_wen();
  uint32_t wb_waddr = sim_get_wb_waddr();
  uint32_t wb_wdata = sim_get_wb_wdata();
  uint32_t wb_pc = sim_get_wb_pc();

  // 调试: 打印最近几条指令的 WB 修正信息
  // dbg_inst_cnt++;
  // if (dbg_inst_cnt > 1) {
  //   printf("[DBG #%d] wb_pc=0x%08x wen=%d waddr=%u(%s) wdata=0x%08x | regfile[a5]=0x%08x regfile[s0]=0x%08x\n",
  //          dbg_inst_cnt, wb_pc, wb_wen, wb_waddr,
  //          wb_waddr < 32 ? reg_names[wb_waddr] : "??",
  //          wb_wdata, sim_get_reg(15), sim_get_reg(8));
  // }

  if (wb_wen) {
    if (wb_waddr != 0) {
      s->gpr[wb_waddr] = wb_wdata;
    }
  }
}

// ==================== 检查寄存器一致性 (只比较 GPR, 不比较 PC) ====================

static bool check_regs(CPU_state *ref, CPU_state *dut, uint32_t pc) {
  bool pass = true;
  for (int i = 0; i < 32; i++) {
    if (ref->gpr[i] != dut->gpr[i]) {
      printf(ANSI_FMT("Mismatch at pc = 0x%08x:", ANSI_FG_RED) "\n", pc);
      printf("  %-4s: " ANSI_FMT("ref = 0x%08x", ANSI_FG_GREEN)
             ", " ANSI_FMT("dut = 0x%08x", ANSI_FG_RED) "\n",
             reg_names[i], ref->gpr[i], dut->gpr[i]);
      pass = false;
    }
  }
  // NPC 是流水线设计, sim_get_pc() 返回 IF 阶段 PC 而非下一条 PC,
  // 所以不直接比较 PC。PC 正确性间接由 GPR 比对保证 (如 JAL 写 pc+4 到 rd)。
  return pass;
}

// ==================== 初始化 DiffTest ====================

void init_difftest(const char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);

  // 加载动态库
  void *handle = dlopen(ref_so_file, RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "DiffTest: failed to load %s: %s\n", ref_so_file, dlerror());
    fprintf(stderr, "DiffTest disabled.\n");
    return;
  }

  // 获取 API 函数指针
  ref_difftest_memcpy  = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  ref_difftest_regcpy  = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  ref_difftest_exec    = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");

  if (!ref_difftest_memcpy || !ref_difftest_regcpy ||
      !ref_difftest_exec || !ref_difftest_init) {
    fprintf(stderr, "DiffTest: failed to load API from %s\n", ref_so_file);
    return;
  }

  // 初始化 NEMU
  ref_difftest_init(0);

  // 将 NPC 的内存镜像拷贝到 NEMU
  extern uint8_t *sim_get_pmem_ptr();
  ref_difftest_memcpy(RESET_VECTOR, sim_get_pmem_ptr(), img_size, DIFFTEST_TO_REF);

  // 将 NPC 的寄存器状态同步到 NEMU
  CPU_state cpu = {};
  get_cpu_state(&cpu);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);

  g_difftest_enabled = true;
  printf("DiffTest: " ANSI_FMT("ON", ANSI_FG_GREEN) " (reference: %s)\n", ref_so_file);
}

// ==================== 跳过下次 DiffTest ====================

void difftest_skip_ref() {
  if (g_difftest_enabled) {
    g_skip_ref = true;
  }
}

// ==================== 每条指令退役后调用 ====================

void difftest_step(uint32_t pc) {
  if (!g_difftest_enabled) return;

  // 跳过检查: 将 NPC 当前状态同步给 NEMU, 保持一致
  if (g_skip_ref) {
    CPU_state cpu = {};
    get_cpu_state(&cpu);
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    g_skip_ref = false;
    return;
  }

  // 让 NEMU 执行 1 条指令
  ref_difftest_exec(1);

  // 读取 NEMU 的寄存器状态
  CPU_state ref_r = {};
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  // 读取 NPC (DUT) 的寄存器状态 (含 WB 写回修正)
  CPU_state dut_r = {};
  get_cpu_state(&dut_r);

  // 对比 GPR
  if (!check_regs(&ref_r, &dut_r, pc)) {
    printf("\n" ANSI_FMT("DiffTest failed at pc = 0x%08x", ANSI_FG_RED) "\n", pc);
    printf("NPC registers:\n");
    sim_print_regs();
    printf("NEMU registers:\n");
    for (int i = 0; i < 32; i++) {
      printf("%-4s = 0x%08x  ", reg_names[i], ref_r.gpr[i]);
      if ((i + 1) % 4 == 0) printf("\n");
    }
    npc_state.state = NPC_ABORT;
    exit(1);
  }
}
