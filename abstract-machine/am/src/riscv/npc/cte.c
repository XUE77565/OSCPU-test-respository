#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  uint32_t cause = c->mcause;
  if (user_handler) {
    Event ev = {0};
    switch (cause) {
      case 11: 
        if((int)c->GPR1 == -1) {ev.event = EVENT_YIELD;}
        else {ev.event = EVENT_SYSCALL;} break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    c->mepc += 4;  // ecall保存的是自身PC，需要跳到下一条指令
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  //在栈底构造一个Context结构体
  Context *cp = (Context *)(kstack.end - sizeof(Context));
  //清零所有字段
  memset(cp, 0, sizeof(Context));
  //设置初始值
  cp->mstatus = 0x1800;
  cp->mepc = (uintptr_t)entry - 4; // 因为__am_irq_handle中会对mepc += 4，这里先减去4以抵消
  //printf("[INFO]kcontext: entry = 0x%08x\n", cp->mepc);
  cp->gpr[10] = (uintptr_t)arg;
  return cp;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
