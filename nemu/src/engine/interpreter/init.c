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
extern word_t expr(char *e, bool *success);

static word_t cmd_p_test(char *args) {

  bool *success = false;
  word_t res = expr(args, success);
  return res;
  
}

void test_cmd_p(){
    FILE *file = fopen("/home/myuser/ysyx/ysyx-workbench/nemu/tools/gen-expr/input", "r"); // 打开文件
    if (!file) {
        perror("无法打开文件");
        return;
    }

    char line[MAX_LINE];   // 存储每一行
    char A[11] = ""; // 存储第一个数字
    char B[MAX_LINE] = ""; // 存储其余内容

    while (fgets(line, sizeof(line), file)) { // 读取每一行
    
      //  使用 sscanf 读取第一个数字
      if (sscanf(line, "%s %[^\n]", A, B) == 2) {

          char * endptr ;
          word_t real = (word_t) strtoul(A, &endptr, 0);

          word_t res = cmd_p_test(B);
          if(real != res){
            fprintf(stderr, "real is %u, res is %u\n", real, res);
          } 
      }
    }


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
