#include "Vysyx_24100005_top___024root.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <Vysyx_24100005_top.h>
#include <stdio.h>
#include <string.h>

VerilatedContext* contextp = new VerilatedContext;
VerilatedVcdC* tfp = NULL;
static TOP_NAME top;

extern "C" int npcmem_read(int raddr) {
  uint32_t aligned_addr = raddr & (~0x3u);
  return 1;
}

void single_cycle() {

  contextp->timeInc(1);
  top.clk = 0; top.eval();
  tfp->dump(contextp->time());

  contextp->timeInc(1);
  top.clk = 1; top.eval();
  tfp->dump(contextp->time());

}


void reset(int n) {

  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;

}

int main(int argc, char *argv[]) {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();

  contextp->traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc/simx.vcd");
  
  reset(3);

  tfp->close();


}
