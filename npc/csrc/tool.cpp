#include "npc_common.h"
#include "Vysyx_24100005_top___024root.h"ak
#define PG_ALIGN __attribute((aligned(4096)))
#define RESET_VECTOR 0x80000000
#define NPC_MSIZE 0x8000000
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

static uint8_t pmem[NPC_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

void npc_reg_display(){
  for (int i = 0;  i< 32; i ++){
    printf("%08x\n", top.rootp->ysyx_24100005_top__DOT__RegFile__DOT__rf[i]);
  }
}

static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}

static uint32_t pmem_read(uint32_t addr) {
  printf("addr = %x\n", addr);
  uint32_t ret = host_read(guest_to_host(addr));
  return ret;
}


void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}

void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

void npc_execute_once(){
    top.inst = pmem_read(top.PC);
    single_cycle();
}

static long load_img(char* img_file) {
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

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

void init_img(char* img_file){

  memcpy(guest_to_host(0x80000000), img, sizeof(img));
  load_img(img_file);
}