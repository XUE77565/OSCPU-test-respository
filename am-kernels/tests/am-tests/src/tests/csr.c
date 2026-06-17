#include <amtest.h>

// ============================================================================
// NPC CSR 测试: 验证 mcycle / mvendorid / marchid
//   - mcycle:    每周期 +1 的计数器, 连续多次读取应单调递增
//   - mvendorid: 只读常量, 应为 0x79737978 (即 "ysyx" 的 ASCII)
//   - marchid:   只读常量, 应为学号的数字部分
//
// 运行: make ARCH=riscv32e-npc mainargs=c run
//
// !!! 重要: mcycle 部分必须在【关闭 DiffTest】时运行 !!!
//   NPC 每周期 +1, NEMU(ref) 每条指令 +1, 两者计数对不上;
//   一旦把 mcycle 读进通用寄存器, DiffTest 在第一条 csrr 处就会报 GPR 不一致。
//   运行本测试前请把 npc/csrc/main.cpp 里的 #define DIFFTEST 改成 0 再重编。
//   (mvendorid/marchid 是确定常量, 开 DiffTest 也能过, 所以也可以单独验证)
// ============================================================================

// csrr 是 csrrs 的伪指令 (csrr rd, csr  ==  csrrs rd, csr, x0)
// RV32E 只能用 x0~x15, 这里用 "=r" 约束让编译器自己挑合法寄存器
static inline uint32_t csr_read_mcycle(void) {
  uint32_t v;
  asm volatile ("csrr %0, mcycle" : "=r"(v));
  return v;
}
static inline uint32_t csr_read_mvendorid(void) {
  uint32_t v;
  asm volatile ("csrr %0, mvendorid" : "=r"(v));
  return v;
}
static inline uint32_t csr_read_marchid(void) {
  uint32_t v;
  asm volatile ("csrr %0, marchid" : "=r"(v));
  return v;
}

// mcycle: 连续读 5 次, 检查是否单调递增
static void test_mcycle(void) {
  printf("\n[mcycle] read mcycle 5 times:\n");
  uint32_t prev = csr_read_mcycle();
  int ok = 1;
  for (int i = 0; i < 5; i++) {
    uint32_t cur = csr_read_mcycle();
    if (cur > prev) {
      printf("  mcycle = %u  (+%u)\n", cur, cur - prev);
    } else {
      printf("  mcycle = %u  (NOT increasing! prev=%u)\n", cur, prev);
      ok = 0;
    }
    prev = cur;
  }
  printf("[mcycle] auto-increment: %s\n", ok ? "PASS" : "FAIL");
}

// mvendorid / marchid: 应分别得到 "ysyx" 和学号数字
static void test_id(void) {
  uint32_t vendor = csr_read_mvendorid();
  uint32_t arch   = csr_read_marchid();

  // mvendorid = 0x79737978, 从高字节到低字节正是 'y','s','y','x'
  char ys[5];
  ys[0] = (char)((vendor >> 24) & 0xff); // 'y'
  ys[1] = (char)((vendor >> 16) & 0xff); // 's'
  ys[2] = (char)((vendor >>  8) & 0xff); // 'y'
  ys[3] = (char)((vendor >>  0) & 0xff); // 'x'
  ys[4] = '\0';

  printf("\n[mvendorid] = 0x%08x  (\"%s\", expect \"ysyx\")\n", vendor, ys);
  printf("[marchid]   = %u  (0x%08x)  <- 应是你的学号数字部分\n", arch, arch);
}

void csr_test(void) {
  printf("==== CSR test ====\n");
  test_id();
  test_mcycle();
  printf("==== CSR test done ====\n");
}
