<<<<<<< HEAD
<<<<<<< HEAD
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


  long img_size = init_img(argv[1]);
  printf("image init success\n");

  init_elf(argv[2]);
  printf("elf init success\n");

  init_disasm("riscv32-pc-linux-gnu");
  printf("disasm init success\n");

  init_difftest(argv[3], img_size, 1);
  printf("difftest init success\n");

  npc_sdb_mainloop();

  end_wave();

}
=======
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vexample.h"
#include "verilated.h"

// while (1) {
=======
#include <nvboard.h>
#include <Vtop.h>
#include <iostream>
>>>>>>> f2d33a7 (>)


static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

<<<<<<< HEAD
         }
      delete top;
      delete contextp;
      return 0;
  }
>>>>>>> b1cfd9b (> sim RTL)
=======
  while(1) {
    nvboard_update();
    dut.eval();
  }
}
>>>>>>> f2d33a7 (>)
