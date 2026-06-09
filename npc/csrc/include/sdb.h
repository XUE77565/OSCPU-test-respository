#ifndef SDB_H__
#define SDB_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <common.h>

// 仿真状态
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

// 全局仿真状态
typedef struct {
  int state;
  uint64_t nr_inst;  // 已执行的指令数
} NPCState;

extern NPCState npc_state;

// ==================== SDB 接口 ====================
void sdb_mainloop();
void sdb_set_batch_mode();

// ==================== 仿真控制 (main.cpp) ====================
void sim_init(const char *bin_path);
bool sim_clock_step();
void sim_exec(uint64_t n);

// ==================== 寄存器访问 (main.cpp, Verilator 内部信号) ====================
uint32_t sim_get_pc();
uint32_t sim_get_reg(int idx);
void sim_print_regs();

// ==================== 内存访问 (main.cpp) ====================
uint32_t sim_pmem_read(uint32_t addr, int len);
uint8_t* sim_get_pmem_ptr();  // 获取 pmem 基地址, 用于 DiffTest 内存拷贝

// ==================== 表达式求值 (expr.cpp / expreval.cpp) ====================
uint32_t expr(char *e, bool *success);
void init_regex();

// ==================== Watchpoint ====================
#define EXPR_LEN 128
typedef struct watchpoint {
  int NO;
  char expr[EXPR_LEN];
  uint32_t old_value;
  struct watchpoint *next;
} WP;

void init_wp_pool();
WP* new_wp();
void free_wp(WP *wp);
bool delete_wp_by_no(int no);
bool check_watchpoints();
void wp_display();

// ==================== DiffTest (difftest.cpp) ====================
void init_difftest(const char *ref_so_file, long img_size);
void difftest_step(uint32_t pc);
void difftest_skip_ref();

#endif
