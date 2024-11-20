#include "npc_common.h"
#include "Vysyx_24100005_top___024root.h"
#define PG_ALIGN __attribute((aligned(4096)))
#define RESET_VECTOR 0x80000000
#define NPC_MSIZE 0x8000000
static TOP_NAME top;
static int state = 1;
unsigned int pre_pc;

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

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

typedef struct {
    const char *name;
    __uint32_t value;
} RegisterMap;

const RegisterMap register_map[] = {
    {"$0", 0}, {"ra", 1}, {"sp", 2}, {"gp", 3}, {"tp", 4},
    {"t0", 5}, {"t1", 6}, {"t2", 7}, {"s0", 8}, {"s1", 9},
    {"a0", 10}, {"a1", 11}, {"a2", 12}, {"a3", 13}, {"a4", 14},
    {"a5", 15}, {"a6", 16}, {"a7", 17}, {"s2", 18}, {"s3", 19},
    {"s4", 20}, {"s5", 21}, {"s6", 22}, {"s7", 23}, {"s8", 24},
    {"s9", 25}, {"s10", 26}, {"s11", 27}, {"t3", 28}, {"t4", 29},
    {"t5", 30}, {"t6", 31}, {"pc", 32}
};

const char *regs[] = {
"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


static uint8_t pmem[NPC_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

void npc_reg_display(){
  for (int i = 0;  i< 32; i ++){
    printf("%-4s =  0x%08x\n",regs[i], top.rootp->ysyx_24100005_top__DOT__RegFile__DOT__rf[i]);
  }
}

extern "C" void ebreak() {
  printf("hit at goog trap\n");
  state = 0;
}

static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}

static uint32_t pmem_read(uint32_t addr) {
  // printf("addr = %x\n", addr);
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
    pre_pc = top.PC;
    single_cycle();
}

void npc_execute(__uint64_t n){
    for (;n > 0; n --) {
      npc_execute_once();
#if 1
    char logbuf[128];
    char *p = logbuf;
    p += snprintf(p, sizeof(logbuf), "0x%08x:", pre_pc);
    int ilen = top.PC - pre_pc;
    int i;
    uint8_t *inst = (uint8_t *)&(top.inst);
    // 按照小端模式打印，i从3开始，但是这里似乎直接 %x 打印就好了，不需要这么麻烦
    for (i = ilen - 1; i >= 0; i --) {
      p += snprintf(p, 4, " %02x", inst[i]);
    }
    int ilen_max = 4;
    int space_len = ilen_max - ilen;
    if (space_len < 0) space_len = 0;
    space_len = space_len * 3 + 1;
    memset(p, ' ', space_len);
    p += space_len;
    
    disassemble(p, logbuf + sizeof(logbuf) - p, pre_pc, (uint8_t *)&(top.inst), ilen);
    printf("%s\n", logbuf);
#endif
      if(state == 0) break;
  }
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