#include "npc_common.h"
#include <dlfcn.h>
#include "tool.h"

extern CPU_state cpu;
extern int npc_state;

void update_cpu();

void (*ref_difftest_memcpy)(unsigned int addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;


static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };


void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(unsigned int, void*, size_t, bool)) dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

//   ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
//   assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  printf("Differential testing: ON");
  printf("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);

  update_cpu(); 
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

bool isa_difftest_checkregs(CPU_state *ref_r) {
    if(ref_r->pc != cpu.pc) {
      printf("ref_r->pc = %x,  cpu.pc = %x\n", ref_r->pc, cpu.pc);
      return false;
      }
    for(int i = 0; i < 16; i++){
      if(ref_r->gpr[i] != cpu.gpr[i]){
      printf("ref_r->gpr[%d]  = %x, cpu.gpr[%d] = %x\n", i, ref_r->gpr[i], i, cpu.gpr[i]);

      return false;
    }
  }
  return true;
}

static void checkregs(CPU_state *ref) {
  if (!isa_difftest_checkregs(ref)) {
    npc_reg_display();
    npc_state = 0;
  }
}

void difftest_step() {
  CPU_state ref_r;

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  update_cpu();
  checkregs(&ref_r);
}