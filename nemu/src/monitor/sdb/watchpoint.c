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
  if(head == NULL && free_ == wp_pool){
    head = &wp_pool[0];
    head->next = NULL;

    free_ = &wp_pool[1];
    return head;
  }
  else if(free_ == NULL){
    fprintf(stderr, "No resources in pool");
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
    return head;
  }
}

void free_wp(WP *wp){
    WP *tmp = free_;
    free_ = wp;
    free_->next = tmp;
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

  // cur->expression = args;
  cur->cur_value = res;
}

void difftest_wp(){
    WP *tmp = free_;
    free_->next = tmp;
    printf("1234\n");
}