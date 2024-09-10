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

#include <cpu/cpu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 65536 + 1024

void sdb_mainloop();
extern int cmd_p(char *args);

void test_cmd_p(){
    FILE *file = fopen("/home/myuser/ysyx/ysyx-workbench/nemu/tools/gen-expr/input", "r"); // 打开文件
    if (!file) {
        perror("无法打开文件");
        return;
    }

    char line[MAX_LINE];   // 存储每一行
    char A[10] = ""; // 存储第一个数字
    char B[MAX_LINE] = ""; // 存储其余内容

    while (fgets(line, sizeof(line), file)) { // 读取每一行
      char tempA[MAX_LINE], tempB[MAX_LINE];
    
    // 使用 sscanf 读取第一个数字
    if (sscanf(line, "%s %[^\n]", tempA, tempB) == 2) {
        strcpy(A, tempA);
        strcpy(B, tempB);
        printf("%s \n", A);
        printf("%s \n", B);
    }
    }
    
    printf("字符串 A: \n%s\n", A);
    printf("字符串 B: \n%s\n", B);

    fclose(file);
    return;
}

void engine_start() {
#ifdef CONFIG_TARGET_AM
  cpu_exec(-1); 
#else
  /* Receive commands from user. */
  #if 0
    sdb_mainloop();
  #else
    test_cmd_p();
  #endif
#endif
}
