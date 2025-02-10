#include <common.h>
#include "syscall.h"

void strace(int type, int a0, int a1, int a2){
    switch (type) {
    case 0:  Log("SYSCALL name : SYS_exit, ARG0 is %d,  ARG1 is %d, ARG2 is %d, no return", a0, a1, a2);  break;
    case 1:  Log("SYSCALL name : SYS_yield, ARG0 is %d,  ARG1 is %d, ARG2 is %d, Return  is %d", a0, a1, a2, 0);  break;
    default: panic("Unhandled syscall ID = %d", type);
  }
}

  // ,
  // ,
  // SYS_open,
  // SYS_read,
  // SYS_write,
  // SYS_kill,
  // SYS_getpid,
  // SYS_close,
  // SYS_lseek,
  // SYS_brk,
  // SYS_fstat,
  // SYS_time,
  // SYS_signal,
  // SYS_execve,
  // SYS_fork,
  // SYS_link,
  // SYS_unlink,
  // SYS_wait,
  // SYS_times,
  // SYS_gettimeofday

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1; // a7
  a[1] = c->GPR2; // a0
  a[2] = c->GPR3; // a1
  a[3] = c->GPR4; // a2

// #ifdef CONFIG_STRACE
  strace(a[0], a[1], a[2], a[3]);
// #endif

  switch (a[0]) {
    case 0:  halt(a[1]);  break;
    case 1:  yield(); c->GPRx = 0; break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
