#include "npc_common.h"
#include "tool.h"
#include <readline/readline.h>
#include <readline/history.h>

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define NR_CMD ARRLEN(cmd_table)

extern int npc_state;
static int is_batch_mode = true;

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

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
  npc_execute(-1);
  return 0;
}

static int cmd_q(char *args) {
  npc_state = 0;
  return -1;
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
  // 返回的是uint8的地址.
  uint8_t * int8_addr =  guest_to_host(addr);

  for (int i = 0; i < len; i++ ) {
    printf("0x%08x : 0x", 0x80000000 + i);
    printf("%02x\n", int8_addr[i]);
  }

  return 0;
}

static int cmd_si(char *args) {
  
  char *endptr;
  uint64_t steps;

  if(args == NULL) steps = 1;
  // si每次最多只打印9条指令
  else steps = strtoul(args, &endptr, 0);

  npc_execute(steps);

  return 0;
}

static int cmd_info(char *args) {
  
  if(args == NULL){
    printf("cmd between 'r', 'w'\n");
        return 0;
  }

  if (strcmp(args, "r") == 0) {
      npc_reg_display();
    } else if (strcmp(args, "w") == 0) {
        npc_reg_display();// 没有实现监视点
    }else{
        printf("cmd between 'r', 'w'\n");
    }
  return 0;
}


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "c", "Continue the execution of the program", cmd_c },
  { "si", "Single  step", cmd_si },
  { "x", "print memory info", cmd_x },
  { "info", "print watchpoint/register info", cmd_info },
  { "q", "Exit npc_sdb", cmd_q }
  /* TODO: Add more commands */

};



void npc_sdb_mainloop() {
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