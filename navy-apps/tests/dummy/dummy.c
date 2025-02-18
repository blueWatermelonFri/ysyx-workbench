// #include <stdint.h>

// #ifdef __ISA_NATIVE__
// #error can not support ISA=native
// #endif

// #define SYS_yield 1
// extern int _syscall_(int, uintptr_t, uintptr_t, uintptr_t);

int xxxx = (0);

int main() {
  char A[100];
  sprintf(A, "old=%x\n", xxxx); 
  write(1, A, 14);
  return xxxx;
}
