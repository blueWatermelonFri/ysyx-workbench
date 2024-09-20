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

#include "sdb.h"

#define NR_WP 32

#define EXPR_LEN 65536
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expression [EXPR_LEN];
  word_t cur_value ;
  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

static int NUM_WP = 0 ;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(){
  if(NUM_WP == 0){
    head = &wp_pool[0];
    head->next = NULL;
    free_ = &wp_pool[1];
    NUM_WP += 1;
    return head;
  }
  else if(NUM_WP == 32){
    fprintf(stderr, "ERROR : No resources in wp pool!\n");
    assert(0);
  }
  else{
    WP *tmp = head;
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = free_;
    free_ = free_->next ;
    tmp->next->next = NULL;
    NUM_WP += 1;
    return head;
  }
}

void wp(char * args){
  
  head = new_wp();

  bool success = false;
  word_t res = expr(args, &success);
  assert(success);

  WP *cur = head;
  while(cur->next!=NULL){
    cur = cur->next;
  }

  strcpy(cur->expression, args);
  cur->cur_value = res;

}

void display_wp(){
    WP *tmp = head;
    int count = 1;
    
    printf("%-8s %-18s %s\n", "Num", "Type", "What");
    while(tmp != NULL){
    
    // The %-8s (and similar) format specifiers tell printf to print a string (s)
    // or a number (d, lx for unsigned long hex) with a width of 8, left-aligned (-).
    printf("%-8d %-18s %s\n", count, "watchpoint", tmp->expression);
    tmp = tmp->next;
    count += 1;
    }

}

void free_wp(char *args){
  
  // bug:从long强制转换为int可能会出现数据溢出的问题
  char *endp;
  int N = (int)strtol(args, &endp, 0);
  assert(N>=1 && N <= NUM_WP);

  if(N == 1){
    WP *tmp = head;
    head = head->next;
    tmp->next = free_;
    free_ = tmp;
    NUM_WP -= 1;
    return;
  }

  WP *prev = head;
  WP *cur = prev->next;

  while(N - 1 > 1){
    prev = prev->next;
    cur = cur->next;
    N -= 1;
  }

  prev->next = cur->next;
  cur->next = free_;
  free_ = cur;
  NUM_WP -= 1;
  
}


void difftest_wp(){
    WP *cur = head;
    int flag = 0;
    int count = 1;
    word_t res;
    bool success;
    while(cur != NULL){
        success = false;
        res = expr(cur->expression, &success);
        assert(success);
        if(res != cur->cur_value){
          if(flag == 0){
            printf("%-8s %-18s %-18s %s\n", "Num", "What", "Prev value", "Cur value");
          }
          flag = 1;
          cur->cur_value = res;
            printf("%-8d %-18s %-18d %d\n", count, cur->expression, cur->cur_value, res);
        }
    }

    if(flag == 1){
      nemu_state.state = NEMU_STOP;
    }

    return;
}