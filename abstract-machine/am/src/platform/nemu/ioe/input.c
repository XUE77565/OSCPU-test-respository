#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t key_value = inl(KBD_ADDR);
  printf("key_value = 0x%08x\n", key_value);
  kbd->keydown = (key_value & KEYDOWN_MASK) != 0;//检查是否按下按键
  kbd->keycode = key_value & ~KEYDOWN_MASK;
}
