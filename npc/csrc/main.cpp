#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vtop.h>
#include <nvboard.h>
#include "verilated.h"
#include "verilated_vcd_c.h"

static TOP_NAME top;

int main() {

  int tmp = 1000;
  while (tmp >0) {
    int a = rand() & 1;
    int b = rand() & 1;
    top.a = a;
    top.b = b;
    top.eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top.f);
    assert(top.f == (a ^ b));
    tmp -= 1;
  }
}
