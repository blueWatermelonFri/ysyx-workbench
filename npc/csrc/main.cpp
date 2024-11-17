#include <Vysyx_24100005_top.h>
// #include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
// #include <stdio.>

#define PG_ALIGN __attribute((aligned(4096)))
#define RESET_VECTOR 0x80000000
static TOP_NAME top;

// dummy 
static const uint32_t img [] = {
	0x00000413,
	0x00009117,
	0xffc10113,
	0x00c000ef,
	0x00000513,
	0x00008067,
	0xff410113,
	0x00000517,
	0x01c50513,
	0x00112423,
	0xfe9ff0ef,
	0x00050513,
	0x00100073,
	0x0000006f
};



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

static char *img_file = NULL;
static long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if(!fp){
    printf("Can not open '%s'", img_file);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}


extern "C" void ebreak() {
  printf("hit at goog trap\n");
  exit(0);
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

int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  memcpy(guest_to_host(0x80000000), img, sizeof(img));
  printf("%s\n", argv[0]);
  printf("%s\n", argv[1]);
  

  load_img();

  reset(3);

  int tmp = 10;
  while (1) {
    top.inst = pmem_read(top.PC);
    single_cycle();
    tmp --;
  }
}
