#include <am.h>
#include <nemu.h>

// 0x8000只有16位
#define KEYDOWN_MASK 0x8000

static uint32_t read_key() {
  uint32_t key = *(volatile uint32_t *)(KBD_ADDR);
  return key;
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t tmp = read_key();
  kbd->keycode = tmp & 0x007f;
  kbd->keydown = tmp & KEYDOWN_MASK;
}
