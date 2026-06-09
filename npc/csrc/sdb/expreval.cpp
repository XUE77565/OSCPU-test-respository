/***************************************************************************************
 * 表达式递归求值 — 移植自 NEMU nemu/src/monitor/sdb/expreval.c
 * 适配 NPC: TK_REG 使用 sim_get_reg + 寄存器名查找, TK_DEREF 使用 sim_pmem_read
 ***************************************************************************************/

#include "../include/sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Token 类型 (必须与 expr.cpp 一致)
enum {
  TK_NOTYPE = 256,
  TK_EQ,
  TK_HEX,
  TK_DEC,
  TK_REG,
  TK_NEQ,
  TK_DEREF,
  TK_AND,
};

// Token 结构 (必须与 expr.cpp 一致)
typedef struct token {
  int type;
  char str[32];
} Token;

// RISC-V 32 寄存器名称
static const char *reg_names[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// 寄存器名 → 索引, 返回 -1 表示未找到
static int reg_str2val(const char *name) {
  for (int i = 0; i < 32; i++) {
    if (strcmp(name, reg_names[i]) == 0) return i;
  }
  // 别名
  if (strcmp(name, "zero") == 0) return 0;
  if (strcmp(name, "fp") == 0)   return 8;  // s0 = fp
  return -1;
}

// 前向声明
bool check_parentheses(int p, int q, Token *tokens);
int find_main_operator(int p, int q, Token *tokens);
bool valid_parentheses(Token *tokens, int nr_token);

// 递归求值
int expreval(int p, int q, Token *tokens, bool *success) {
  if (p > q) {
    *success = false;
    printf("Bad expression\n");
    return 0;
  }
  else if (p == q) {
    if (tokens[p].type == TK_HEX) {
      *success = true;
      return (int)strtoul(tokens[p].str, NULL, 16);
    }
    else if (tokens[p].type == TK_DEC) {
      *success = true;
      return (int)strtoul(tokens[p].str, NULL, 10);
    }
    else if (tokens[p].type == TK_REG) {
      *success = true;
      // 去掉 '$' 前缀
      char reg_name[32];
      memset(reg_name, 0, sizeof(reg_name));
      strncpy(reg_name, tokens[p].str + 1, sizeof(reg_name) - 1);
      int idx = reg_str2val(reg_name);
      if (idx == -1) {
        *success = false;
        printf("Unknown register: %s\n", reg_name);
        return 0;
      }
      return (int)sim_get_reg(idx);
    }
    else {
      *success = false;
      printf("Unexpected token at [%d]: type=%d, str='%s'\n", p, tokens[p].type, tokens[p].str);
      return 0;
    }
  }
  else if (check_parentheses(p, q, tokens)) {
    return expreval(p + 1, q - 1, tokens, success);
  }
  else {
    int op = find_main_operator(p, q, tokens);
    if (op == -1) {
      *success = false;
      printf("No operator found in expression\n");
      return 0;
    }

    int val1 = 0, val2 = 0;

    if (tokens[op].type == TK_DEREF) {
      // 单目运算符: 只求右侧
      val2 = expreval(op + 1, q, tokens, success);
      if (!*success) return 0;
    }
    else {
      val1 = expreval(p, op - 1, tokens, success);
      if (!*success) return 0;
      val2 = expreval(op + 1, q, tokens, success);
      if (!*success) return 0;
    }

    switch (tokens[op].type) {
      case TK_EQ:   return val1 == val2;
      case TK_NEQ:  return val1 != val2;
      case TK_AND:  return val1 && val2;
      case '+':     return val1 + val2;
      case '-':     return val1 - val2;
      case '*':     return val1 * val2;
      case '/':
        if (val2 == 0) {
          *success = false;
          printf("Division by zero\n");
          return 0;
        }
        return val1 / val2;
      case TK_DEREF:
        return (int)sim_pmem_read((uint32_t)val2, 4);
      default:
        *success = false;
        printf("Unknown operator: %d\n", tokens[op].type);
        return 0;
    }
  }
}

// 检查 tokens[p..q] 是否被一对匹配的括号包围
bool check_parentheses(int p, int q, Token *tokens) {
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }
  int depth = 0;
  for (int i = p + 1; i < q; i++) {
    if (tokens[i].type == '(') depth++;
    else if (tokens[i].type == ')') {
      if (depth == 0) return false;
      depth--;
    }
  }
  return true;
}

// 找主运算符 (优先级最低且最右边的双目运算符)
int find_main_operator(int p, int q, Token *tokens) {
  int main_op = -1;
  int min_priority = 100;
  int depth = 0;

  for (int i = p; i <= q; i++) {
    if (tokens[i].type == TK_HEX || tokens[i].type == TK_DEC || tokens[i].type == TK_REG) {
      continue;
    }
    else if (tokens[i].type == '(') {
      depth++;
    }
    else if (tokens[i].type == ')') {
      depth--;
    }
    else if (depth == 0) {
      int priority;
      switch (tokens[i].type) {
        case TK_AND:          priority = 0; break;
        case TK_EQ:
        case TK_NEQ:          priority = 1; break;
        case '+':
        case '-':             priority = 2; break;
        case '*':
        case '/':             priority = 3; break;
        case TK_DEREF:        priority = 4; break;
        default:              priority = 100; break;
      }
      // 同优先级取最右 (双目), 单目 (TK_DEREF) 取最左
      if (priority < min_priority ||
          (priority == min_priority && tokens[i].type != TK_DEREF)) {
        min_priority = priority;
        main_op = i;
      }
    }
  }
  return main_op;
}

// 验证括号合法性
bool valid_parentheses(Token *tokens, int nr_token) {
  int depth = 0;
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '(') depth++;
    else if (tokens[i].type == ')') {
      depth--;
      if (depth < 0) return false;
    }
  }
  return depth == 0;
}
