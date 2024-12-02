#include "npc_common.h"
#include "sdb.h"
#include "tool.h"


int main(int argc, char *argv[]) {

  init_wave();

  reset(5);

  single_cycle();

  single_cycle();


  end_wave();

}
