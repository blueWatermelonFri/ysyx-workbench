#include <Vysyx_24100005_top.h>
// #include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"

#define PG_ALIGN __attribute((aligned(4096)))
static TOP_NAME top;

// INSTPAT("0000000 00001 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00010 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00011 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00110 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00111 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 01000 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 01001 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);


    // 00100093
    // 00200093
    // 00300093
    // 00600093
    // 00700093
    // 00800093
    // 00900093
static const uint32_t img [] = {
  0x00100093,  // pcaddu12i $t0,0
  0x00200093,  // st.w $zero,$t0,16
  0x00300093,  // ld.w $a0,$t0,16
  0x00600093,  // break 0 (used as nemu_trap)
  0x00700093,  // some data
  0x00100073,
  0x00800093,
  0x00900093,
};


extern "C" void ebreak() {
  printf("hit at goog trap\n");
  exit(0);
}


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

  reset(5);

  int tmp = 10;
  while (tmp) {
    top.inst = pmem_read(top.PC);
    single_cycle();
    tmp --;
  }
}
