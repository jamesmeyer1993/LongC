#ifndef _FUNCTON_H_
#define _FUNCTION_H_

#include "primitives.h"

struct node {
  struct node *next;
  struct node *prev;
  void *elem;
};

struct fn {
  struct node *head;
  struct node *tail;
};

void fn_own(void* elem);

void fn_give(void* elem, struct fn *f);

void fn_lend(void* elem, struct fn *f);

void fn_borrow(void* elem, struct fn *f);

void fn_free(struct fn *f);

#endif
