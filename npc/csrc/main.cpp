// #include <nvboard.h>
#include "npc_common.h"
#include "sdb.h"
#include "tool.h"


// void nvboard_bind_all_pins(TOP_NAME* top);
extern "C" void init_disasm(const char *triple);


int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  init_img(argv[1]);

  init_disasm("riscv32" "-pc-linux-gnu");

  reset(3);

  npc_sdb_mainloop();

}
