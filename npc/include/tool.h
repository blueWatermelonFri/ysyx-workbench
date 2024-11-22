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
#ifndef __TOOL_H__
#define __TOOL_H__

#include <npc_common.h>

#define RESET_VECTOR 0x80000000
#define RGE_NUM 32
typedef struct {
  unsigned int gpr[RGE_NUM];
  unsigned int pc;
} CPU_state;

void npc_execute(__uint64_t n);
void single_cycle();
void reset(int n);

int init_img(char* img_file);
uint8_t* guest_to_host(uint32_t paddr);
void npc_reg_display();

#endif