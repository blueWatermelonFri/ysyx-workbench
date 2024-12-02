#include "npc_common.h"
#include "sdb.h"
#include "tool.h"

extern "C" void init_disasm(const char *triple);
void init_elf(const char *filename);
void init_difftest(char *ref_so_file, long img_size, int port);


int main(int argc, char *argv[]) {

  init_wave();

  reset(5);

  single_cycle();

  single_cycle();


  end_wave();

}
