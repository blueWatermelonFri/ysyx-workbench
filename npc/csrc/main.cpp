// #include <nvboard.h>
#include "npc_common.h"
#include "sdb.h"
#include "tool.h"


// void nvboard_bind_all_pins(TOP_NAME* top);
extern "C" void init_disasm(const char *triple);
void init_elf(const char *filename);
void init_difftest(char *ref_so_file, long img_size, int port);


int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  reset(3);

  printf("%s\n", argv[1]);

  long img_size = init_img(argv[1]);

  init_elf(argv[2]);

  init_disasm("riscv32-pc-linux-gnu");

  init_difftest(argv[3], img_size, 1);

  npc_sdb_mainloop();

}
