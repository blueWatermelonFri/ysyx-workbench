#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

char* itoa(int value, char*string ){
  
  int i = 0;
  int remainder;
  char tmp;

  if(value < 0){
    string[i++] = '-';
	  value = abs(value);
  }

  for(; value % 10 >= 0 && value > 0; ){
    remainder = value % 10;
    value = value / 10;
	  
    string[i++] = remainder + 48;
  }
  
  string[i] = '\0';
  int end = strlen(string) - 1;
  int start = string[0] == '-' ? 1 : 0;
  int middle = string[0] == '-' ? (end - start) / 2 + 1 : (end - start) / 2;

  while(start <= middle){
    tmp = string[end];
    string[end] = string[start];
    string[start] = tmp;
	  
	  start += 1;
	  end -=1;
  }

  return string;

}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  panic("Not implemented");
#endif
  return NULL;
}

void free(void *ptr) {
}

#endif
