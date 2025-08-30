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
#include "verilated.h"

// while (1) {
<<<<<<< HEAD
=======
#include <nvboard.h>
#include <Vtop.h>
#include <iostream>
>>>>>>> f2d33a7 (>)
=======
>>>>>>> 35ceda6 (> compile NEMU)


// }

int main(int argc, char** argv) {
      int a = rand() & 1;
      int b = rand() & 1;
      VerilatedContext* contextp = new VerilatedContext;
      contextp->commandArgs(argc, argv);
      Vexample* top = new Vexample{contextp};
      
    contextp->traceEverOn(true); // 生成波形文件使用，打开追踪功能

      while (!contextp->gotFinish()) {
        top->a = a;
        top->b = b;
        top->eval();
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        assert(top->f == (a ^ b));
                contextp->timeInc(1); // 时间+1，推动仿真时间

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
