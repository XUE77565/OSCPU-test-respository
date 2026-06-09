/***************************************************************************************
 * 表达式词法分析 — 移植自 NEMU nemu/src/monitor/sdb/expr.c
 * 适配 NPC: 不依赖 NEMU 的 isa.h / memory/paddr.h
 ***************************************************************************************/

#include "../include/sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <regex.h>

// Token 类型 (>= 256 避免与 ASCII 字符冲突)
enum {
  TK_NOTYPE = 256,
  TK_EQ,          // ==
  TK_HEX,         // 0x...
  TK_DEC,         // 十进制数
  TK_REG,         // $reg
  TK_NEQ,         // !=
  TK_DEREF,       // * (解引用)
  TK_AND,         // &&
};

// Token 结构
typedef struct token {
  int type;
  char str[32];
} Token;

// 正则规则
static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},                        // 空格
  {"\\(", '('},                              // 左括号
  {"\\)", ')'},                              // 右括号
  {"\\*", '*'},                              // 乘号 / 解引用
  {"/", '/'},                                // 除号
  {"\\+", '+'},                              // 加号
  {"-", '-'},                                // 减号
  {"==", TK_EQ},                             // 等于
  {"!=", TK_NEQ},                            // 不等于
  {"0[xX][0-9a-fA-F]+", TK_HEX},            // 十六进制数
  {"[0-9]+", TK_DEC},                        // 十进制数
  {"\\$[a-zA-Z]+[0-9]*", TK_REG},           // 寄存器 ($ra, $s0, $t0 等)
  {"&&", TK_AND}                             // 逻辑与
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

// 编译所有正则表达式 (只需调用一次)
void init_regex() {
  int i;
  char error_msg[128];
  int ret;
  for (i = 0; i < NR_REGEX; i++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      fprintf(stderr, "regex compilation failed: %s\n%s\n", error_msg, rules[i].regex);
      assert(0);
    }
  }
}

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

// 判断 '*' 是解引用还是乘法
static bool check_deref(Token *tokens, int nr_token) {
  if (nr_token >= 2) {
    int last = tokens[nr_token - 2].type;
    if (last == TK_NOTYPE || last == '(' ||
        last == '+' || last == '-' ||
        last == '*' || last == '/' ||
        last == TK_EQ || last == TK_NEQ ||
        last == TK_AND) {
      return true;
    }
  } else if (nr_token == 1) {
    return true;  // 首个 token 的 '*' 一定是解引用
  }
  return false;
}

// 词法分析: 将字符串 e 切分为 token 序列
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

        if (rules[i].token_type != TK_NOTYPE) {
          if (nr_token >= 65536) {
            printf("Too many tokens\n");
            return false;
          }
          memset(tokens[nr_token].str, 0, sizeof(tokens[nr_token].str));
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].type = rules[i].token_type;
          nr_token++;

          // 检查是否为解引用
          if (tokens[nr_token - 1].type == '*' && check_deref(tokens, nr_token)) {
            tokens[nr_token - 1].type = TK_DEREF;
          }
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

// 前向声明 (实现在 expreval.cpp 中)
extern int expreval(int p, int q, Token *tokens, bool *success);
extern bool valid_parentheses(Token *tokens, int nr_token);

// 表达式求值入口
uint32_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  int p = 0;
  int q = nr_token - 1;

  if (!valid_parentheses(tokens, nr_token)) {
    *success = false;
    printf("Invalid parentheses in expression: %s\n", e);
    return 0;
  }

  word_t result = (uint32_t)expreval(p, q, tokens, success);

  if (!*success) {
    printf("Failed to evaluate expression: %s\n", e);
    return 0;
  }
  return result;
}
