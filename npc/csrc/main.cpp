#include <Vysyx_24100005_top.h>
// #include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
// #include <stdio.>

#define PG_ALIGN __attribute((aligned(4096)))
static TOP_NAME top;

static const uint32_t img [] = {
  // 0000  0000 0001 0000 0000 0000 1001 0011
  //      0000 01000 001 0011
  //      1001 00010 001 0111
    0x00000413, //  li	s0,0 load immedate
    0x00009117, //  auipc	sp,0x9 ; rd = PC + (imm << 12)
    0xffc10113, //  addi	sp,sp,-4 # 80009000 <_end>
    0x00c000ef, //  jal	80000018 <_trm_init>
    0x00000513, //  li	a0,0
    0x00008067, //  ret
    0xff010113, //  addi	sp,sp,-16
    0x00000517, //  auipc	a0,0x0
    0x01c50513, //  addi	a0,a0,28 # 80000038 <_etext>
    0x00112623, //  sw	ra,12(sp) //行为位实现

    // 0xfe9ff0ef, //  jal	80000010 <main>
    // 0x00050513, //  mv	a0,a0
    // 0x00100073, //  ebreak
    // 0x0000006f, //  j	80000034 <_trm_init+0x1c>
};


// static char *img_file = NULL;

// static long load_img() {
//   if (img_file == NULL) {
//     Log("No image is given. Use the default build-in image.");
//     return 4096; // built-in image size
//   }

//   FILE *fp = fopen(img_file, "rb");
//   Assert(fp, "Can not open '%s'", img_file);

//   fseek(fp, 0, SEEK_END);
//   long size = ftell(fp);

//   Log("The image is %s, size = %ld", img_file, size);

//   fseek(fp, 0, SEEK_SET);
//   int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
//   assert(ret == 1);

//   fclose(fp);
//   return size;
// }

// INSTPAT("0000000 00001 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00010 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00011 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00110 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 00111 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 01000 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);
// INSTPAT("0000000 01001 00000 000 00001 00100 11", addi   , I, R(rd) = src1 + imm);

extern "C" void ebreak() {
  printf("hit at goog trap\n");
  exit(0);
}


static uint8_t pmem[4*1000] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}

static uint32_t pmem_read(uint32_t addr) {
  printf("addr = %x\n", addr);
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

  reset(3);

  int tmp = 10;
  while (tmp) {
    top.inst = pmem_read(top.PC);
    single_cycle();
    tmp --;
  }
}
