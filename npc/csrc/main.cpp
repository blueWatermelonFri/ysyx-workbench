// #include <nvboard.h>
#include "npc_common.h"
#include "sdb.h"
#include "tool.h"


// void nvboard_bind_all_pins(TOP_NAME* top);
extern "C" void init_disasm(const char *triple);
void init_elf(const char *filename);


int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  printf("%s\n", argv[1]);
  printf("%s\n", argv[2]);

  init_img(argv[1]);

  init_elf(argv[2]);

  init_disasm("riscv32" "-pc-linux-gnu");

  reset(3);

  npc_sdb_mainloop();

}
