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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  PLUS,
  SUB,
  MUL,
  DIV,
  LBRACKET,
  RBRACKET,
  NUMBER,
  TK_EQ,
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {" +", TK_NOTYPE},    // spaces
  {"\\+", PLUS},         // plus
  {"-", SUB},           // sub
  {"\\*", MUL},         // multiply
  {"\\/", DIV},         // divide
  {"\\(", LBRACKET},         // divide
  {"\\)", RBRACKET},         // divide
  {"-?[0-9]+", NUMBER}, // decimalism integer
  {"==", TK_EQ},        // equal
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
    int count = 0;
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case PLUS:
            tokens[count].type = PLUS;
            break;
          case SUB:
            tokens[count].type = SUB;
            break;
          case MUL:
            tokens[count].type = MUL;
            break;
          case DIV:
            tokens[count].type = DIV;
            break;
          case LBRACKET:
            tokens[count].type = LBRACKET;
            break;
          case RBRACKET:
            tokens[count].type = RBRACKET;
            break;         
          case NUMBER:
            assert (substr_len < sizeof(tokens[count].str));
            tokens[count].type = NUMBER;
            strncpy(tokens[count].str, substr_start, substr_len);
            break; 
          default :
            break;
        }

        break;
      }

    }
    
    count += 1;
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

    printf("%d, %s\n", tokens[0].type, tokens[0].str);
    printf("%d, %s\n", tokens[1].type, tokens[1].str);    
    printf("%d, %s\n", tokens[2].type, tokens[2].str);    
    printf("%d, %s\n", tokens[3].type, tokens[3].str);    
    printf("%d, %s\n", tokens[4].type, tokens[4].str);    
    printf("%d, %s\n", tokens[5].type, tokens[5].str);  
    printf("%d, %s\n", tokens[6].type, tokens[6].str);
    printf("%d, %s\n", tokens[7].type, tokens[7].str);    
    printf("%d, %s\n", tokens[8].type, tokens[8].str);    
    printf("%d, %s\n", tokens[9].type, tokens[9].str);    
    printf("%d, %s\n", tokens[10].type, tokens[10].str);    
    printf("%d, %s\n", tokens[11].type, tokens[11].str);          
    printf("%d, %s\n", tokens[12].type, tokens[12].str);          
    printf("%d, %s\n", tokens[13].type, tokens[13].str);          
    printf("%d, %s\n", tokens[14].type, tokens[14].str);          
    printf("%d, %s\n", tokens[15].type, tokens[15].str);          
    printf("%d, %s\n", tokens[16].type, tokens[16].str);    
    printf("%d, %s\n", tokens[17].type, tokens[17].str);    
    printf("%d, %s\n", tokens[18].type, tokens[18].str); 
    printf("%d, %s\n", tokens[19].type, tokens[19].str); 
    printf("%d, %s\n", tokens[20].type, tokens[20].str); 

  return true;
}


word_t expr(char *e, bool *success) {


  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
//   TODO();

  return 0;
}
