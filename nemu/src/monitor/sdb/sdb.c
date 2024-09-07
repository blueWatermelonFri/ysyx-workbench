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

static int cmd_r() {
  isa_reg_display();
  return 0;
}

static int cmd_si(char *args) {
  
  char *endptr;

  uint64_t steps = strtoul(args, &endptr, 0);
  cpu_exec(steps);
  return 0;
}

static int cmd_x(char *args) {

  char *str_len = strtok(args, " ");
  args = str_len + strlen(str_len) + 1;
  char *str_addr = strtok(args, " ");

  // 只支持32位的地址
  assert(strlen(str_addr) == 10);
  
  char *endptr;
  // if  base is zero or 16, the string may then include a "0x" prefix, and  the
  //  number  will  be read in base 16; 
  // printf("%s\n", str_addr);
  uint64_t steps = strtoul(str_addr, &endptr, 0);
  // int len = (int) strtoul(str_len, &endptr, 0);

  printf("%ld", steps);
  uint32_t addr1 = (uint32_t) steps;
  uint32_t val1 =  vaddr_ifetch(addr1, 4);
  uint8_t * int8_addr = (uint8_t *)& val1;
  printf("\n");
  
  for (int j = 3; j >= 0 ; j --) {
    printf("%02x", int8_addr[j]);
  }
  printf("\n");
  addr1 = (uint32_t) (steps + 4);
   val1 =  vaddr_ifetch(addr1, 4);
  int8_addr = (uint8_t *)& val1;
  
  for (int j = 3; j >= 0 ; j --) {
    printf("%02x", int8_addr[j]);
  }
  printf("\n");

    printf("%p", &val1);

    // printf("%x", val);
    // printf("%x", val);
    // printf("%02x", pmem[6]);


  // for (int i = 39; i >= 0; i --) {
  //   printf("%02x", int8_addr[i]);
  //   if( i % 4 == 0)
  //     printf("\n");
  // }

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
  { "r", "print register info", cmd_r },
  { "x", "print memory info", cmd_x },

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
