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

  init_wave();

  reset(3);



  npc_sdb_mainloop();


}
