#include <common.h>
#include "syscall.h"

void strace(int a0, int a1, int a2, int a3, int return_value ){
  switch (a0) {
  case 0:  Log("SYSCALL name : SYS_exit, ARG0 is %d,  ARG1 is %d, ARG2 is %d, no return", a1, a2, a3);  break;
  case 1:  Log("SYSCALL name : SYS_yield, ARG0 is %d,  ARG1 is %d, ARG2 is %d, Return is %d", a1, a2, a3, return_value);  break;
  case 4:  Log("SYSCALL name : SYS_write, fd is %d,  buf addr is %x, count is %d, Return is %d", a1, a2, a3, return_value);  break;
  case 9:  Log("SYSCALL name : SYS_brk, new pb is %x,  ARG1 is %x, ARG2 is %d, Return is %x", a1, a2, a3, return_value);  break;
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

int heap_addr_bound(uintptr_t heap_addr){

  if(heap_addr > 0x87ffffff || heap_addr < 0x83000000)
    return -1;
  else
    return 0;
}

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1; // a7
  a[1] = c->GPR2; // a0
  a[2] = c->GPR3; // a1
  a[3] = c->GPR4; // a2

  intptr_t return_value = 0;

  // #ifdef CONFIG_STRACE
  strace(a[0], a[1], a[2], a[3], return_value);
  // #endif

  switch (a[0]) {
    case 0:  halt(a[1]);  break;
    case 1:  yield(); break;    
    case 4:  return_value = write_to_serial(a[1], (void *) a[2], a[3]); break;    
    // case 9:  return_value = heap_addr_bound(a[1]); break;    
    case 9:  return_value = 0; break;    
    default: panic("Unhandled syscall ID = %d", a[0]);
  }

  c->GPRx = return_value;

}
