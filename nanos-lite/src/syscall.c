#include <common.h>
#include "syscall.h"

void strace(uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t return_value){
  switch (a0) {
    case 0:  Log("SYS_exit, arg1 : %d, arg2 : %d, arg3 : %d, return value is none", a1, a2, a3); break;
    case 1:  Log("SYS_yield, arg1 : %d, arg2 : %d, arg3 : %d, return value is none", a1, a2, a3); break;
    case 4:  Log("SYS_write, arg1 : %x, arg2 : %d, arg3 : %d, return value is %d", a1, a2, a3, return_value);  break;
    case 9:  Log("SYS_sbrk, arg1 : %x, arg2 : %d, arg3 : %d, return value is %d", a1, a2, a3, return_value);  break;
    default: panic("Unhandled syscall ID = %d", a0);
  }

}

int write_to_serial(int fd, void *buf, size_t count){

  const unsigned char *p1 = (const unsigned char *) buf;

  if(fd == 1 || fd == 2){
    for(int i = 0; i < count; i++){
      putch(p1[i]);
    }
    return count;
  }

  return -1;
}


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  intptr_t return_value = 0;

  switch (a[0]) {
    case 0:  halt(a[1]);  break;
    case 1:  yield(); break;
    case 4:  return_value = write_to_serial(a[1], (void *)a[2], a[3]);  break;
    case 9:  return_value = 0;  break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }


// #ifdef CONFIG_STRACE
  strace(a[0], a[1], a[2], a[3], return_value);
// #endif

  c->GPRx = return_value;
}
