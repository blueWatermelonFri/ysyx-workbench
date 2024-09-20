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
    fprintf(stderr, "ERROR : No resources in wp pool\n");
    assert(0);
  }
  else{
    wp_pool[NUM_WP-1].next = &(wp_pool[NUM_WP]);
    // 必须在下面这句赋值之前，不然会导致下次迭代有free_ = NULL->next;
    free_ = free_->next; 

    wp_pool[NUM_WP].next = NULL;
    NUM_WP += 1;
    printf("1111111\n");
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

  // if(N == 1){
    
  // }
  // WP *pre = head;
  // WP *cur = head->next;
  
  // while(N - 1 > 1 )
  
}


void difftest_wp(){
    WP *tmp = free_;
    free_->next = tmp;
    printf("1234\n");
}