#include "verilated.h"
#include "verilated_vcd_c.h"
#include <Vysyx_24100005_top.h>
#include <stdio.h>
#include <string.h>

VerilatedContext* contextp = new VerilatedContext;
VerilatedVcdC* tfp = NULL;
static TOP_NAME top;

void single_cycle() {

  top.clk = 1; top.sig = 1; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());

  top.clk = 0; top.sig = 0; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());

}


void reset(int n) {

  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;

}


int main(int argc, char *argv[]) {

  contextp->traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc_demo_demo/simx.vcd");

  reset(5);

  single_cycle();

  single_cycle();

  single_cycle();

  single_cycle();


  tfp->close();

}
