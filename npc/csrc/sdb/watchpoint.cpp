#include "../include/sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

//添加一个新的watchpoint
WP* new_wp() {
  if(free_ == NULL) {
    printf("No free watchpoint\n");
    assert(0);
    return NULL;
  }
  WP *wp = free_;
  free_ = free_->next;
  wp->next = head;
  head = wp;
  return wp;
}

void free_wp(WP *wp) {
  if(wp == NULL) {
    printf("Cannot free a NULL watchpoint\n");
    assert(0);
    return;
  }
  WP *prev = NULL, *cur = head;
  while(cur != NULL) {
    if(cur == wp) {
      //wp是头节点
      if(prev == NULL) {
        head = cur->next;
      }
      //删除cur节点
      else {
        prev->next = cur->next;
      }
      //将cur节点加入free链表而且重置表达式
      memset(cur->expr, 0, sizeof(cur->expr));
      cur->next = free_;
      free_ = cur;
      return;
    }
    prev = cur;
    cur = cur->next;
  }
  printf("Cannot find the watchpoint to free\n");
}

bool delete_wp_by_no(int no) {
  WP *wp = head;
  while(wp != NULL) {
    if(wp->NO == no) {
      free_wp(wp);
      return true;
    }
    wp = wp->next;
  }
  return false;
}

//检查监视点的值是否发生变化
bool check_watchpoints() {
  bool changed = false;
  WP *wp = NULL;
  bool success;
  for(wp = head; wp != NULL; wp = wp->next) {
    uint32_t new_value = expr(wp->expr, &success);
    if(success == false) {
      printf("Failed to evaluate the expression of watchpoint %d: %s\n", wp->NO, wp->expr);
      continue;
    }
    if(new_value != wp->old_value) {
      npc_state.state = NPC_STOP;
      printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
      printf("Old value = 0x%08x\n", wp->old_value);
      printf("New value = 0x%08x\n", new_value);
      wp->old_value = new_value;
      changed = true;
    }
  }
  return changed;
}

void wp_display() {
  WP *wp = NULL;
  printf("%-8s %-24s %s\n", "Num", "Expression", "Old Value");
  for(wp = head; wp != NULL; wp = wp->next) {
    printf("%-8d %-24s 0x%08x\n", wp->NO, wp->expr, wp->old_value);
  }
}