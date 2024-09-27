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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void wp();
void display_wp();
void free_wp();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}


static int cmd_info(char *args) {
  
  if(args == NULL){
    printf("cmd between 'r', 'w'\n");
        return 0;
  }

  if (strcmp(args, "r") == 0) {
      isa_reg_display();
    } else if (strcmp(args, "w") == 0) {
        display_wp();
    }else{
        printf("cmd between 'r', 'w'\n");
    }
  return 0;
}


static int cmd_si(char *args) {
  
  char *endptr;
  uint64_t steps;

  if(args == NULL) steps = 1;
  else steps = strtoul(args, &endptr, 0);
  cpu_exec(steps);

  return 0;
}

static int cmd_x(char *args) {
  // str_len表示从当前地址开始，打印多少个地址的值
  char *str_len = strtok(args, " ");
  args = str_len + strlen(str_len) + 1;
  char *str_addr = strtok(args, " ");

  assert(str_len != NULL && str_addr != NULL);

  // 只支持0x开始32位的地址，以字符串的形式输入，所以是10位数字
  assert(strlen(str_addr) == 10);

  char *endptr;
  // if  base is zero or 16, the string may then include a "0x" prefix, and  the
  //  number  will  be read in base 16; 
  uint32_t addr = (uint32_t) strtoul(str_addr, &endptr, 0);
  assert (addr >= 0x80000000);
  /* Check for various possible errors , from man 3 strtol*/
  if (endptr == str_addr) {
        fprintf(stderr, "No digits were found\n");
        exit(EXIT_FAILURE);
  }

  int len = (int) strtoul(str_len, &endptr, 0);
  assert(len > 0);

  if (endptr == str_len) {
        fprintf(stderr, "No digits were found\n");
        exit(EXIT_FAILURE);
  }

  // 小端模式 数据的低字节保存在内存的低地址中
  // 返回的是uint8的地址，为了方便起见，直接转化为
  // uint32地址，但是必须保证地址是32的整数倍？
  uint8_t * int8_addr =  guest_to_host(addr);
  
  for (int i = 0; i < len; i++ ) {
    printf("%08x : 0x", 0x80000000 + 4 * i);
    for (int j = 3; j >= 0 ; j --) {
      printf("%02x", int8_addr[i * 4 + j]);
  }
    printf("\n");
}

  return 0;
}

static int cmd_p(char *args) {

  bool success = false;
  word_t res = expr(args, &success);
  printf("%-14s %-s\n", "DEC", "HEX");
  printf("%14u 0x%08x\n", res, res);
  return 0;
  
}

static int cmd_w(char *args) {
  
  if( args == NULL){
    printf("a expr must be followed cmd w\n");
    return 0;
  }
  wp(args);

  return 0;
}

static int cmd_d(char *args) {
  
  free_wp(args);

  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single  step", cmd_si },
  { "info", "print watchpoint/register info", cmd_info },
  { "x", "print memory info", cmd_x },
  { "p", "get expr value", cmd_p },
  { "w", "watchpoint", cmd_w },
  { "d", "delete watch point", cmd_d }

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
