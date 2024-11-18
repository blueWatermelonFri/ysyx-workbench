// #include <nvboard.h>
#include "npc_common.h"
#include "sdb.h"
#include "tool.h"


extern "C" void ebreak() {
  printf("hit at goog trap\n");
  exit(0);
}

// void nvboard_bind_all_pins(TOP_NAME* top);


int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();
  init_img(argv[1]);

  reset(3);

  npc_sdb_mainloop();

}
