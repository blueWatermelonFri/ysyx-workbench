/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
   printf("reg0 = 0x%d\n", cpu.gpr[0]);
   printf("reg1 = 0x%d\n", cpu.gpr[1]);
   printf("reg2 = 0x%d\n", cpu.gpr[2]);
   printf("reg3 = 0x%d\n", cpu.gpr[3]);
   printf("reg4 = 0x%d\n", cpu.gpr[4]);
   printf("reg5 = 0x%d\n", cpu.gpr[5]);
   printf("reg6 = 0x%d\n", cpu.gpr[6]);
   printf("reg7 = 0x%d\n", cpu.gpr[7]);
   printf("reg8 = 0x%d\n", cpu.gpr[8]);
   printf("reg9 = 0x%d\n", cpu.gpr[9]);
  printf("reg10 = 0x%d\n", cpu.gpr[10]);
  printf("reg11 = 0x%d\n", cpu.gpr[11]);
  printf("reg12 = 0x%d\n", cpu.gpr[12]);
  printf("reg13 = 0x%d\n", cpu.gpr[13]);
  printf("reg14 = 0x%d\n", cpu.gpr[14]);
  printf("reg15 = 0x%d\n", cpu.gpr[15]);
  printf("reg16 = 0x%d\n", cpu.gpr[16]);
  printf("reg17 = 0x%d\n", cpu.gpr[17]);
  printf("reg18 = 0x%d\n", cpu.gpr[18]);
  printf("reg19 = 0x%d\n", cpu.gpr[19]);  
  printf("reg20 = 0x%d\n", cpu.gpr[20]);
  printf("reg21 = 0x%d\n", cpu.gpr[21]);
  printf("reg22 = 0x%d\n", cpu.gpr[22]);
  printf("reg23 = 0x%d\n", cpu.gpr[23]);
  printf("reg24 = 0x%d\n", cpu.gpr[24]);
  printf("reg25 = 0x%d\n", cpu.gpr[25]);
  printf("reg26 = 0x%d\n", cpu.gpr[26]);
  printf("reg27 = 0x%d\n", cpu.gpr[27]);
  printf("reg28 = 0x%d\n", cpu.gpr[28]);
  printf("reg29 = 0x%d\n", cpu.gpr[29]);
  printf("reg30 = 0x%d\n", cpu.gpr[30]);
  printf("reg31 = 0x%d\n", cpu.gpr[31]);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  return 0;
}
