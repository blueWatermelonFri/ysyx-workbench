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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = "{}";
static char code_buf[65536 + 1024] = {}; // a little larger than `buf`
static int count = 0; 

static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned int result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
static int choose(int n){
  return rand() % n ;
}

static void gen_rand_op(){
  // 防止出现一个运算符后面没有表达式这种情况
  if(count + 1 > 65000)
    return; 

  int op =  rand() % 4 ;
  switch (op) {
    case 0: buf[count] = '+'; break;
    case 1: buf[count] = '-';  break;
    case 2: buf[count] = '*';; break;
    case 3: buf[count] = '/';  break;
    default : assert(0);
  }
  count ++;
}

static void gen(char str){
  // 防止出现()这种情况
  if(count + 1 > 65000)
    return; 
  buf[count] = str;
  count ++;
}

static void gen_num(){
  uint32_t op =  rand() % 65536;
  // op的最大值是10位有效数字，加上'\0'字符，一共最多11个字符，
  // 但是返回值不会包括'\0'。
  count += snprintf(buf + count, 11, "%uu", op);

}


static void gen_rand_expr() {
  if (count > 65000)
    return;

  switch (choose(5)) {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    case 2: gen(' '); gen_rand_expr(); break;
    case 3: gen(' '); gen_rand_expr(); break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }

}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    
    count = 0;
    gen_rand_expr();
    
    if(count > 65535)
      continue;

    buf[count] = '\0';

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c  -Werror -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}

