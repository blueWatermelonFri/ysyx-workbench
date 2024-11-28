#include "Vysyx_24100005_top___024root.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <Vysyx_24100005_top.h>
#include <stdio.h>
#include <string.h>

VerilatedContext* contextp = new VerilatedContext;
VerilatedVcdC* tfp = NULL;
static TOP_NAME top;

int main(int argc, char *argv[]) {

  contextp->traceEverOn(true);
  tfp = new VerilatedVcdC;
  top.trace(tfp, 0);
  tfp->open("/home/myuser/ysyx/ysyx-workbench/npc/simx.vcd");
  
  top.rst = 1;
  
  contextp->timeInc(1);
  top.clk = 0; 
  top.eval();
  tfp->dump(contextp->time());

  contextp->timeInc(1);
  top.clk = 1; 
  top.eval();
  tfp->dump(contextp->time());

  top.rst = 0;

  tfp->close();
}
