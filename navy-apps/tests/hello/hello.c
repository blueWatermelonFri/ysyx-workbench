#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  write(1, "Hello World!\n", 13);
  char * tmp = (char *)malloc(20);
  tmp [0] = '1';
  tmp [1] = '2';
  tmp [2] = '3';
  tmp [3] = '4';
  tmp [4] = '5';
  tmp [5] = '\0';

  printf("Hello World from Navy-apps for the %sth time!\n", tmp);

  int i = 2;
  volatile int j = 0;
  while (1) {
    j ++;
    if (j == 10000) {
      printf("Hello World from Navy-apps for the %dth time!\n", i ++);
      j = 0;
    }
  }
  return 0;
}
