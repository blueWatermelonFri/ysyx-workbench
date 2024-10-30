#include <Vysyx_24100005_top.h>
// #include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "svdpi.h"
#include "Vysyx_24100005_top__Dpi.h"


int add(int a, int b) { return a+b; }
static TOP_NAME top;


static void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}


int main() {
  // nvboard_bind_all_pins(&top);
  // nvboard_init();


  int tmp = 6;
  while (tmp) {
    single_cycle();
    tmp --;
  }
}
