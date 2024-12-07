#include "npc_common.h"
#include "Vysyx_24100005_top___024root.h"
#include "tool.h"

#define PG_ALIGN __attribute((aligned(4096)))
#define RESET_VECTOR 0x80000000
#define NPC_MSIZE 0x8000000
#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define INST_LEN 4 //指令的长度， 4字节

// 必须要先new， 不可以 VerilatedContext* contextp = nullptr;
VerilatedContext* contextp = new VerilatedContext;
VerilatedVcdC* tfp = new VerilatedVcdC;

static TOP_NAME top;


int npc_state = 1;
unsigned int pre_pc;
unsigned int instruction;

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


CPU_state cpu;
void update_cpu(){
  for(int i = 0; i<16; i++){
    cpu.gpr[i] = top.rootp->ysyx_24100005_top__DOT__RegFile__DOT__rf[i];
  }
  cpu.pc = top.PC;
}

static uint8_t pmem[NPC_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

void npc_reg_display(){
  update_cpu();
  for (int i = 0;  i< 16; i ++){
    printf("%-4s =  0x%08x\n",regs[i], cpu.gpr[i]);
  }
}

static inline uint32_t host_read(void *addr) {
    return *(uint32_t *)addr;
}

static inline void host_write(void *addr, int wdata, char wmask) {
  if( (wmask & 0x1u) == 1) {*(uint8_t  *)addr = (wdata & 0x000000ff);}
  if( ((wmask >> 1) & 0x1u) == 1) {* ((uint8_t  *)addr + 1)= (unsigned int)(wdata & 0x0000ff00) >> 8;} // 确保wmask是正数，以及移位做0拓展
  if( ((wmask >> 2) & 0x1u) == 1) {* ((uint8_t  *)addr + 2)= (unsigned int)(wdata & 0x00ff0000) >> 16;} 
  if( ((wmask >> 3) & 0x1u) == 1) {* ((uint8_t  *)addr + 3)= (unsigned int)(wdata & 0xff000000) >> 24;} 
}

static void check_addr(uint32_t addr) {
 if(addr < 0x80000000 || addr > 0x87ffffff){
    end_wave();
    printf("addr not in [0x80000000, 0x87ffffff]");
  }
}
static uint32_t pmem_read(uint32_t addr) {
  // printf("read addr %x\n", addr);
  
  check_addr(addr);
  uint32_t ret = host_read(guest_to_host(addr));
  return ret;
}

static void pmem_write(uint32_t addr, int wdata, char wmask) {
  // printf("write addr %x\n", addr);
  check_addr(addr);
  // printf("write addr %x\n", addr);
  host_write(guest_to_host(addr), wdata, wmask);

}

extern "C" void ebreak() {
  printf("hit at goog trap\n");
  npc_state = 0;
}

extern "C" int npcmem_read(int raddr) {
  // printf("npcmem_read = %x\n", raddr);
  uint32_t aligned_addr = raddr & (~0x3u);
  return pmem_read(aligned_addr);
}

extern "C" void npcmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  // printf("write_addr = %x\n", waddr);
  uint32_t aligned_addr = waddr & (~0x3u);
  printf("write addr = %x, data = %x\n", aligned_addr, wdata);

  return pmem_write(aligned_addr, wdata, wmask);
}

void single_cycle() {

  top.clk = 0; 
  top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
  
  top.clk = 1; 
  top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());

}

void init_wave(){
  contextp->traceEverOn(true);
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc/simx.vcd");
}

void end_wave(){  
  tfp->close();
}

void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

void npc_execute_once(){
    // instruction = pmem_read(top.PC);
    // printf("top.pc %x\n", top.PC);
    pre_pc = top.PC;
    instruction = pmem_read(top.PC);
    single_cycle();
}

void npc_execute(__uint64_t n){
    for (;n > 0; n --) {
      npc_execute_once();
#if 1
    char logbuf[128];
    char *p = logbuf;
    p += snprintf(p, sizeof(logbuf), "0x%08x:", pre_pc);
    int ilen = INST_LEN; // 优化一下？
    int i;
    uint8_t *inst = (uint8_t *)&(instruction);
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
    
    disassemble(p, logbuf + sizeof(logbuf) - p, pre_pc, (uint8_t *)&(instruction), ilen);
    printf("%s\n", logbuf);
#endif

#if 0
  static int ftrace_cnt = 0; // unit: us
  unsigned int opcode = BITS(instruction, 6, 0);
  if(opcode == 0x0000006f || opcode == 0x00000067){
    // printf("%08x\n",_this->isa.inst.val);
    // s->dnpc表示跳转的下一条指令
    if(instruction == 0x00008067){ 
      for(int i = 0 ; i < ftrace_func_count; i++){
        if(pre_pc >= ftrace_func_begin[i] && pre_pc <= ftrace_func_end[i]){
            printf("0x%08x:%*sret  [%s]\n",pre_pc, ftrace_cnt, "", ftrace_func_name[i]);
            ftrace_cnt --;
            break;
        }
      }

    }
    else{ 
      for(int i = 0 ; i < ftrace_func_count; i++){
        if(top.PC == ftrace_func_begin[i]){
          ftrace_cnt ++;
          printf("0x%08x:%*scall [%s@0x%08x]\n",pre_pc, ftrace_cnt, "",  ftrace_func_name[i], top.PC);
          break;
        }
      }
    }
  }
#endif

#if 1
  difftest_step();
#endif

      if(npc_state == 0) {
        end_wave();
        break;
      }
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

int init_img(char* img_file){

  memcpy(guest_to_host(0x80000000), img, sizeof(img));
  long img_size = load_img(img_file);
  return img_size;
}