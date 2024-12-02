#include "npc_common.h"
#include "Vysyx_24100005_top___024root.h"
#include "tool.h"


VerilatedContext* contextp = new VerilatedContext;

VerilatedVcdC* tfp = NULL;

static TOP_NAME top;



void single_cycle() {

  top.clk = 1; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());


  
  top.clk = 0; top.eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());

  
}

void init_wave(){
  
  contextp->traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc_demo/simx.vcd");
}

void end_wave(){  
  tfp->close();
}
void reset(int n) {

  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;

}
