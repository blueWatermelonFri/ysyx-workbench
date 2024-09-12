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

enum
{
    TK_NOTYPE = 256, // space
    PLUS,            // +
    SUB,             // -
    MUL,             // *
    DIV,             // /
    LBRACKET,        // (
    RBRACKET,        // ）
    NUMBER,          // decimalism
    HEXANUMBER,      // hexadecimal
    REG,             // register
    DEREF,           // dereference
    NEG,             // negtive number
    TK_EQ,           // ==
    AND              // &&
                     // 添加一条规则判断有任意的加减号
                     /* TODO: Add more token types */
};

static struct rule
{
    const char *regex;
    int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     * https://en.cppreference.com/w/c/language/operator_precedence
     */
    {" +", TK_NOTYPE},    // spaces
    {"\\+", PLUS},        // plus
    {"-", SUB},           // sub
    {"\\*", MUL},         // multiply
    {"\\/", DIV},         // divide
    {"\\(", LBRACKET},    // (
    {"\\)", RBRACKET},    // )
    {"-?[0-9]+", NUMBER}, // decimalism unsigned integer
    {"0x[0-9a-fA-F]+", HEXANUMBER}, // hexadecimal unsigned integer
    {"\\$[a-z0-9\\$]+", REG}, // register
    {"==", TK_EQ},        // equal
    {"&&", AND}          // logic and

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */

void init_regex()
{
    int i;
    char error_msg[128];
    int ret;

    for (i = 0; i < NR_REGEX; i++)
    {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0)
        {
            regerror(ret, &re[i], error_msg, 128);
            panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
        }
    }
}

#define TOKEN_NUM 65536
#define TOKEN_STR_NUM 32

typedef struct token
{
    int type;
    char str[TOKEN_STR_NUM];
} Token;


static Token tokens[TOKEN_NUM] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;
    while (e[position] != '\0')
    {
        /* Try all rules one by one. */
        Assert(nr_token < TOKEN_NUM, "token count can not larger than 32");
        for (i = 0; i < NR_REGEX; i++)
        {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
            {
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

                Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                position += substr_len;

                /* TODO: Now a new token is recognized with rules[i]. Add codes
                 * to record the token in the array `tokens'. For certain types
                 * of tokens, some extra actions should be performed.
                 */
                switch (rules[i].token_type)
                {
                case PLUS:
                    tokens[nr_token].type = PLUS;
                    break;
                case SUB:
                    if (nr_token == 0 || tokens[nr_token - 1].type == PLUS ||
                                         tokens[nr_token - 1].type == SUB ||
                                         tokens[nr_token - 1].type == MUL ||
                                         tokens[nr_token - 1].type == DIV ||
                                         tokens[nr_token - 1].type == LBRACKET){
                        tokens[nr_token].type = NEG;
                    }
                    else{
                        tokens[nr_token].type = SUB;
                    }                
                    break;
                case MUL:
                    if (nr_token == 0 || tokens[nr_token - 1].type == PLUS ||
                                           tokens[nr_token - 1].type == SUB ||
                                           tokens[nr_token - 1].type == MUL ||
                                           tokens[nr_token - 1].type == DIV ||
                                           tokens[nr_token - 1].type == LBRACKET){
                        tokens[nr_token].type = DEREF;
                    }
                    else{
                        tokens[nr_token].type = MUL;
                    }
                    break;
                case DIV:
                    tokens[nr_token].type = DIV;
                    break;
                case LBRACKET:
                    tokens[nr_token].type = LBRACKET;
                    break;
                case RBRACKET:
                    tokens[nr_token].type = RBRACKET;
                    break;
                case NUMBER:
                    assert(substr_len < sizeof(tokens[nr_token].str));
                    tokens[nr_token].type = NUMBER;
                    strncpy(tokens[nr_token].str, substr_start, substr_len);
                    tokens[nr_token].str[substr_len] = '\0';
                    break;
                case HEXANUMBER:
                    assert(substr_len < sizeof(tokens[nr_token].str));
                    tokens[nr_token].type = HEXANUMBER;
                    strncpy(tokens[nr_token].str, substr_start, substr_len);
                    tokens[nr_token].str[substr_len] = '\0';
                    break;
                // case REG:
                //     tokens[nr_token].type = REG;
                //     break;                
                case TK_EQ:
                    tokens[nr_token].type = TK_EQ;
                    break;    
                case AND:
                    tokens[nr_token].type = AND;
                    break;                        
                default:
                    break;
                }
                break;
            }
        }

        if(rules[i].token_type != TK_NOTYPE)
            nr_token += 1;


        if (i == NR_REGEX)
        {
            printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
            return false;
        }
    }

    return true;
}

// 寻找主运算符

// 运算符优先级排序
// NEG 0
// MUL, DIV 1
// PLUS, SUB 2
// TK_EQ 3
// AND 4


int  check_op_positions(int p, int q)
{
    int op = 0;
    int in_parentheses = 0;
    int has_lower = 0;

    for(; p <= q; p++){
        
        switch (tokens[p].type){
            case NEG:
                if(!in_parentheses && !has_lower){
                    op = p;
                }
                break;
            case MUL:
                if(!in_parentheses && has_lower <= 1){
                    op = p;
                    has_lower = 1;
                }
                break;
            case DIV:
                if(!in_parentheses && has_lower <= 1){
                    op = p;
                    has_lower = 1;
                }
                break;
            case PLUS:
                if(!in_parentheses && has_lower <= 2){
                    op = p;
                    has_lower = 2;
                }
                break;
            case SUB:
                if(!in_parentheses && has_lower <= 2){
                    op = p;
                    has_lower = 2;
                }
                break;
            case TK_EQ:
                if(!in_parentheses && has_lower <= 3){
                    op = p;
                    has_lower = 3;
                }
                break;
            case AND:
                if(!in_parentheses && has_lower <= 4){
                    op = p;
                    has_lower = 4;
                }
                break;

            case LBRACKET:
                in_parentheses += 1;
                break;
            case RBRACKET:
                in_parentheses -= 1;
                break;
            case NUMBER:
                break;
            case HEXANUMBER:
                break;
            default:
                break;
        }
    }

    return op;
}

int  check_parentheses(int p, int q)
{
    // 断表达式是否被一对匹配的括号包围着,
    // 同时检查表达式的左右括号是否匹配, 
    // 如果不匹配, 这个表达式肯定是不符合语法的
    // 如果结果parentheses != 0, 表达式不合法
    // 如果表达式合法，表达式第一个是左括号，遍历中间存在parentheses==0，返回0
    // 否则返回1
    int parentheses = 0;
    int count = p;
    int matched = 1;

    for(; count <= q; count++){        
        switch (tokens[count].type){
            case LBRACKET:
                parentheses += 1;
                break;
            case RBRACKET:
                parentheses -= 1;
                if(tokens[p].type == LBRACKET && parentheses == 0 && count != q){
                    matched = 0;
                }
                break;
            default:
                break;
        }
    }

    if(parentheses != 0){
        Assert(0, "Input expr's parentheses not complete");
    }

    else if(tokens[p].type == LBRACKET)
        return matched;

    else
        return 0;
}

word_t eval (int p, int q)
{
    if (p > q)
    {
        /* Bad expression */
        fprintf(stderr, "No digits were found\n");
    }
    else if (p == q)
    {   
        char * endptr ;
        uint32_t value = (uint32_t) strtoul(tokens[p].str, &endptr, 0);

        return value;
    }
    else if (check_parentheses(p, q) == true)
    {
        /* The expression is surrounded by a matched pair of parentheses.
         * If that is the case, just throw away the parentheses.
         */

        return eval(p + 1, q - 1);
    }
    else
    {
        int op = check_op_positions(p, q);
        // Assert(op > 0, "Op position must be greater than 0, but got %d", op);

        if(tokens[op].type == NEG)
            return 0 - eval(op + 1, q);                

        
        uint32_t val1 = eval(p, op - 1);

        if(tokens[op].type == AND){
            if(val1 == 0)
                return 0; 
            else
                return val1 && eval(op + 1, q);
        }

        uint32_t val2 = eval(op + 1, q);

        switch (tokens[op].type){
            case PLUS:
                return val1 + val2;
            case SUB:
                return val1 - val2;
            case MUL:
                return val1 * val2;
                break;
            case TK_EQ:
                return val1 == val2;
                break;
            case DIV:
                Assert(val2 != 0, "Zero cannot be devides");
                return val1 / val2;
            default:
                Assert(0, "not support op %d", tokens[op].type);
        }
    }
    return 0;
}

word_t expr(char *e, bool *success)
{

    if (!make_token(e))
    {
        *success = false;
        return 0;
    }

    /* TODO: Insert codes to evaluate the expression. */
    Assert(nr_token - 1 >= 0, "expression is bad!");
    word_t res = eval(0, nr_token - 1);
    printf("%u\n", res);

    return res;
}
