#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

// 静态变量必须在编译时就能确定其值，但 heap.start 是运行时才能确定的。
static char *hbrk = NULL;

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

void string_reverse(char* string) {
  char tmp;

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
}

// string  to integer
int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

// integer to string
void itoa(int value, char*string ){
  
  int i = 0;
  int remainder;
  
  if(value == 0){
    string[i++] = '0';
    string[i] = '\0';
    return ;
  }

  // 如果value小于0，则将value取反，并在string中添加负号
  if(value < 0){
    string[i++] = '-';
	  value = abs(value);
  }

  // 将数字转换为字符串，从个位数开始往前获取每一位数字的ASCII，再取反
  for(; value % 10 >= 0 && value > 0; ){
    remainder = value % 10;
    value = value / 10;
	  
    // 转为ASCII码
    string[i++] = remainder + 48;
  }
  
  string[i] = '\0';

  string_reverse(string);

}

// unsigned integer to hex string
void utostring(unsigned int value, char*string ){

  int i = 0;
  int remainder;
  
  if(value == 0){
    string[i++] = '0';
    string[i] = '\0';
    return ;
  }

  // 将数字转换为字符串，从个位数开始往前获取每一位数字的ASCII，再取反
  for(; value % 10 >= 0 && value > 0; ){ // 这一行是不是可以优化
    remainder = value % 10;
    value = value / 10;
	  
    // 转为ASCII码
    string[i++] = remainder + '0';
  }
  
  string[i] = '\0';

  string_reverse(string);
}

void hex2str(unsigned int value, char*string, unsigned int upper){
  if(value == 0){
    string[0] = '0';
    string[1] = '\0';
    return;
  }
  
  // %x or %X
  const char *hex_digits;  // 将数组声明移到外面
  if(upper == 0){
    hex_digits = "0123456789abcdef";
  }else{
    hex_digits = "0123456789ABCDEF";
  }

  int i = 0;

  while (value > 0) {
      string[i++] = hex_digits[value & 0xf];  // 取最后4位
      value >>= 4;  // 右移4位
  }

  string[i] = '\0';

  string_reverse(string);

  return;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
// #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
//   panic("Not implemented");
// #endif
  if (hbrk == NULL) {
    hbrk = (void *)ROUNDUP(heap.start, 8); // 一定要是8吗
  }
  
  size  = (size_t)ROUNDUP(size, 8);
  char *old = hbrk;
  hbrk += size;
  
  panic_on(!((uintptr_t)heap.start <= (uintptr_t)hbrk && (uintptr_t)hbrk < (uintptr_t)heap.end), "hbrk out of range");
  for (uint64_t *p = (uint64_t *)old; p != (uint64_t *)hbrk; p ++) {
    *p = 0;
  }

  // assert((uintptr_t)hbrk - (uintptr_t)heap.start <= setting->mlim); // 这个mlin是什么，这是bench_alloc的实现
  return old;
}

void free(void *ptr) {
}

#endif
