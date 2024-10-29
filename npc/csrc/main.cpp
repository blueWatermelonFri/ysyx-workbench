#include <Vysyx_24100005_top.h>
// #include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"

#define PG_ALIGN __attribute((aligned(4096)))
static TOP_NAME top;

static const uint32_t img [] = {
  0x1c00000c,  // pcaddu12i $t0,0
  0x29804180,  // st.w $zero,$t0,16
  0x28804184,  // ld.w $a0,$t0,16
  0x002a0000,  // break 0 (used as nemu_trap)
  0xdeadbeef,  // some data
};


static uint8_t pmem[4*10] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}

static uint32_t pmem_read(uint32_t addr) {
  uint32_t ret = host_read(guest_to_host(addr));
  return ret;
}

// void nvboard_bind_all_pins(TOP_NAME* top);

static void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}

static void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

int main() {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  memcpy(guest_to_host(0x80000000), img, sizeof(img));

  reset(10);

  printf("1111111111111111111\n");
  int tmp = 4;
  while (tmp) {
    top.inst = pmem_read(top.PC);
    top.eval();
    printf("1111111111111111111\n");

    tmp --;
  }
}
