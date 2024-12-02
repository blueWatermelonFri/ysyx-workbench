#include "npc_common.h"
#include "Vysyx_24100005_top___024root.h"
#include "tool.h"

#define PG_ALIGN __attribute((aligned(4096)))
#define RESET_VECTOR 0x80000000
#define NPC_MSIZE 0x8000000
#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define INST_LEN 4 //指令的长度， 4字节

// VerilatedVcdC* tfp = new VerilatedVcdC;
// topp->trace(tfp, 99);  // Trace 99 levels of hierarchy (or see below)
// 必须要先new， 不可以 VerilatedContext* contextp = nullptr;
VerilatedContext* contextp = new VerilatedContext;

VerilatedVcdC* tfp = NULL;

static TOP_NAME top;


static int state = 1;
unsigned int pre_pc;

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void difftest_step();

// 用于ftrace
extern uint32_t ftrace_func_begin[100];
extern uint32_t ftrace_func_end[100];
extern uint32_t ftrace_func_count;
extern char ftrace_func_name[100][128];

// dummy 
static const uint32_t img [] = {
    0x00000413,
    0x00009117,
    0xffc10113,
    0xffc10113,
    0xffc10113,
    0x00100073
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


static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}




void single_cycle() {

  top.clk = 1; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());


  
  top.clk = 0; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());

  
}

void init_wave(){
  
  contextp->traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc_demo/simx.vcd");
}

void end_wave(){  
  tfp->close();
}
void reset(int n) {

  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;

}





int init_img(){

  memcpy(guest_to_host(0x80000000), img, sizeof(img));
  return sizeof(img);
}