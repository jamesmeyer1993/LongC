#ifndef _STACKH_
#define _STACKH_

#include "../../byte/byte.h"
#include "../../obj.h"
#include "../../type.h"
#include "../node.h"

#ifndef T_STACK
  #define T_STACK 18
#endif

struct stack
{
  byte T;
  int size;
  int len;
  struct node* head;
  struct node* tail;
};

struct stack newstack(byte t);

void stack_push(struct stack* src, struct obj* elem);

struct obj stack_pop(struct stack* src);

struct obj stack_peek(struct stack* src);

struct list stack_tolist(struct stack* src); // cast up in heriarchy - to parent

struct obj stack_toobj(struct stack* src);

#endif
