#include <unistd.h>
#include <stdio.h>

int main() {
  write(1, "first!\n", 100);
  // printf("xxxxxxxHello World from Navy-apps for the th time!\n");
  // write(1, "Hello World!\n", 13);
  // int i = 2;
  // volatile int j = 0;
  // while (1) {
  //   j ++;
  //   if (j == 10000) {
  //     j = 0;
  //   }
  // }
  _syscall_(SYS_yield, 0, 0, 0);
  write(1, "xxxxx!\n", 10);


  return 0;
}
