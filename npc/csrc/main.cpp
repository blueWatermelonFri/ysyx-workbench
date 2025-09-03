<<<<<<< HEAD
<<<<<<< HEAD
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
=======
>>>>>>> 35ceda6 (> compile NEMU)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vexample.h"
=======
#include <Vlight.h>
#include <nvboard.h>
>>>>>>> 241d764 (> compile NEMU)
#include "verilated.h"
#include "verilated_vcd_c.h"

<<<<<<< HEAD
// while (1) {
<<<<<<< HEAD
=======
#include <nvboard.h>
#include <Vtop.h>
#include <iostream>
>>>>>>> f2d33a7 (>)
=======
>>>>>>> 35ceda6 (> compile NEMU)
=======
static TOP_NAME top;
>>>>>>> 241d764 (> compile NEMU)

void nvboard_bind_all_pins(TOP_NAME* top);

static void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}

static void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

int main() {
  nvboard_bind_all_pins(&top);
  nvboard_init();

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 35ceda6 (> compile NEMU)
         }
      delete top;
      delete contextp;
      return 0;
<<<<<<< HEAD
  }
>>>>>>> b1cfd9b (> sim RTL)
=======
  while(1) {
    nvboard_update();
    dut.eval();
  }
}
>>>>>>> f2d33a7 (>)
=======
  }
>>>>>>> 35ceda6 (> compile NEMU)
=======
  reset(10);

  while(1) {
    nvboard_update();
    single_cycle();
  }
}
>>>>>>> 241d764 (> compile NEMU)
