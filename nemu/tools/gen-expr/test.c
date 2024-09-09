#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) printf("error\n");

    FILE *fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    
    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%d\n", result);

  return 0;
}

