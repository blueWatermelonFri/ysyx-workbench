#include <stdio.h>
int main() { 
  unsigned int result = 5u/(1u&&0u); 
  printf("%u", result); 
  return 0; 
};