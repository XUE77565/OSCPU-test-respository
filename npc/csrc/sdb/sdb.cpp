#include "../include/sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

NPCState npc_state = { .state = NPC_STOP, .nr_inst = 0 };

static bool is_batch_mode = false;

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

// ==================== 命令处理函数 ====================

static int cmd_c(char *args) {
  sim_exec(-1);
  return 0;
}

static int cmd_si(char *args) {
  uint64_t n = 1;
  if (args != NULL) {
    n = atoi(args);
  }
  if (n <= 0) {
    printf("Invalid step count: %s\n", args);
    return 0;
  }
  sim_exec(n);
  return 0;
}

static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  return -1;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info [r|w]\n");
    return 0;
  }
  if (strcmp(args, "r") == 0) {
    sim_print_regs();
  } else if (strcmp(args, "w") == 0) {
    wp_display();
  } else {
    printf("Unknown info subcommand: %s\n", args);
  }
  return 0;
}

// 扫描内存: x N EXPR
// 求值 EXPR 得到起始地址, 打印从该地址开始的 N 个 4 字节
static int cmd_x(char *args) {
  if (args == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  char *arg_end = args + strlen(args);
  char *num_str = strtok(args, " ");
  //printf("cmd_x: num_str='%s'\n", num_str);
  char *expr_str = num_str ? num_str + strlen(num_str) + 1 : NULL;
  //printf("cmd_x: expr_str='%s'\n", expr_str);
  if (expr_str >= arg_end) expr_str = NULL;

  if (num_str == NULL || expr_str == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  int n = atoi(num_str);
  bool success = false;
  uint32_t addr = expr(expr_str, &success);
  printf("cmd_x: n=%d, addr=0x%08x\n", n, addr);
  if (!success) {
    printf("Failed to evaluate expression: %s\n", expr_str);
    return 0;
  }

  for (int i = 0; i < n; i++) {
    uint32_t current_addr = addr + i * 4;
    uint32_t data = sim_pmem_read(current_addr, 4);
    printf("0x%08x: 0x%08x\n", current_addr, data);
  }

  return 0;
}

// 求值表达式并打印结果: p EXPR
static int cmd_p(char *args) {
  if (args == NULL) {
    printf("Usage: p EXPR\n");
    return 0;
  }

  bool success = false;
  uint32_t result = expr(args, &success);
  if (success) {
    printf("= %u (0x%08x)\n", result, result);
  } else {
    printf("Failed to evaluate expression: %s\n", args);
  }
  return 0;
}

// 设置监视点: w EXPR
static int cmd_w(char *args) {
  if (args == NULL) {
    printf("Usage: w EXPR\n");
    return 0;
  }

  bool success = false;
  uint32_t val = expr(args, &success);
  if (!success) {
    printf("Failed to evaluate expression: %s\n", args);
    return 0;
  }

  WP *wp = new_wp();
  strncpy(wp->expr, args, EXPR_LEN - 1);
  wp->expr[EXPR_LEN - 1] = '\0';
  wp->old_value = val;
  printf("Watchpoint %d: %s = 0x%08x\n", wp->NO, wp->expr, wp->old_value);
  return 0;
}

// 删除监视点: d N
static int cmd_d(char *args) {
  if (args == NULL) {
    printf("Usage: d N\n");
    return 0;
  }

  int no = atoi(args);
  if (delete_wp_by_no(no)) {
    printf("Deleted watchpoint %d\n", no);
  } else {
    printf("Watchpoint %d not found\n", no);
  }
  return 0;
}

static int cmd_help(char *args);

// ==================== 命令表 ====================

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands",         cmd_help },
  { "c",    "Continue the execution of the program",                    cmd_c },
  { "q",    "Exit NPC",                                                 cmd_q },
  { "si",   "Execute N instructions (default 1): si [N]",              cmd_si },
  { "info", "Print register/watchpoint status: info [r|w]",            cmd_info },
  { "x",    "Scan memory: x N EXPR",                                   cmd_x },
  { "p",    "Evaluate expression: p EXPR",                             cmd_p },
  { "w",    "Set watchpoint: w EXPR",                                  cmd_w },
  { "d",    "Delete watchpoint: d N",                                  cmd_d },
};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

static int cmd_help(char *args) {
  printf("Usage:\n");
  for (int i = 0; i < (int)NR_CMD; i++) {
    printf("  %-5s - %s\n", cmd_table[i].name, cmd_table[i].description);
  }
  return 0;
}

// ==================== 读取输入行 ====================

static char *rl_gets() {
  static char *line_read = NULL;
  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

// ==================== sdb主循环 ====================

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *end = str + strlen(str);
    // 去除末尾空白
    while (end > str && (*(end - 1) == ' ' || *(end - 1) == '\t' || *(end - 1) == '\n')) {
      end--;
    }
    *end = '\0';

    if (str[0] == '\0') continue;

    // 分割命令和参数
    char *cmd = strtok(str, " ");
    char *args = cmd ? cmd + strlen(cmd) + 1 : NULL;
    if (args >= end) args = NULL;

    // 查找并执行命令
    int i;
    for (i = 0; i < (int)NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) return;
        break;
      }
    }
    if (i == (int)NR_CMD) {
      printf("Unknown command '%s'. Type 'help' for usage.\n", cmd);
    }
  }
}
