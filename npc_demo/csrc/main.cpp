#include "npc_common.h"
#include "sdb.h"
#include "tool.h"

extern "C" void init_disasm(const char *triple);
void init_elf(const char *filename);
void init_difftest(char *ref_so_file, long img_size, int port);


int main(int argc, char *argv[]) {

  init_wave();

  reset(3);

  int img_size = init_img();

  init_disasm("riscv32-pc-linux-gnu");
  printf("disasm init success\n");

  init_difftest(argv[1], img_size, 1);

  printf("difftest init success\n");

  npc_sdb_mainloop();


}
