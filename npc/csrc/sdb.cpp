#include "npc_common.h"
#include "tool.h"
#include <readline/readline.h>
#include <readline/history.h>

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define NR_CMD ARRLEN(cmd_table)



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

void npc_execute(__uint64_t n){
    for (;n > 0; n --) {
      npc_execute_once();
  }
}

void npc_exec(__uint64_t n){
    npc_execute(n);
}


// static int cmd_help(char *args) {
//   /* extract the first argument */
//   char *arg = strtok(NULL, " ");
//   int i;

//   if (arg == NULL) {
//     /* no argument given */
//     for (i = 0; i < NR_CMD; i ++) {
//       printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
//     }
//   }
//   else {
//     for (i = 0; i < NR_CMD; i ++) {
//       if (strcmp(arg, cmd_table[i].name) == 0) {
//         printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
//         return 0;
//       }
//     }
//     printf("Unknown command '%s'\n", arg);
//   }
//   return 0;
// }

static int cmd_c(char *args) {
  npc_exec(-1);
  return 0;
}

// static int cmd_q(char *args) {
//   nemu_state.state = NEMU_QUIT;
//   return -1;
// }

static int cmd_si(char *args) {
  
  char *endptr;
  uint64_t steps;

  if(args == NULL) steps = 1;
  // si每次最多只打印9条指令
  else steps = strtoul(args, &endptr, 0);
  npc_exec(steps);

  return 0;
}

// static int cmd_info(char *args) {
  
//   if(args == NULL){
//     printf("cmd between 'r', 'w'\n");
//         return 0;
//   }

//   if (strcmp(args, "r") == 0) {
//       isa_reg_display();
//     } else if (strcmp(args, "w") == 0) {
//         display_wp();
//     }else{
//         printf("cmd between 'r', 'w'\n");
//     }
//   return 0;
// }


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "c", "Continue the execution of the program", cmd_c },
//   { "q", "Exit npc_sdb", cmd_q },
  { "si", "Single  step", cmd_si },
//   { "info", "print watchpoint/register info", cmd_info },
  /* TODO: Add more commands */

};



void npc_sdb_mainloop() {
  // if (is_batch_mode) {
  //   cmd_c(NULL);
  //   return;
  // }

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