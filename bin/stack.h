#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include "lang.h"

#define PUSH(T_SELF, T_ELEM) T_ELEM##T_SELF##_push

#define POP(T_SELF, T_ELEM) T_ELEM##T_SELF##_pop

#define PEEK(T_SELF, T_ELEM) T_ELEM##T_SELF##_peek

struct node {
  struct node* next;
  const void* elem;
};

typedef struct stack {
  struct node* head;
  size_t len;
  struct impl_stack* fn;
} Stack;

typedef struct impl_stack {
  Stack* (*new)();
  Stack (*init)();
  void (*push)(struct stack*,const void*);
  struct node* (*pop)(struct stack*);
  struct node* (*peek)(struct stack*);
} ImplStack;

Stack* NEW(Stack)(ImplStack* methods);

Stack INIT(Stack)(ImplStack* methods);

void PUSH(Stack,void)(Stack* self, const void* elem);

struct node* POP(Stack,void)(Stack* self);

struct node* PEEK(Stack,void)(const Stack* self);

ImplStack* NEW(ImplStack)();

ImplStack INIT(ImplStack)();

#endif /* _STACK_H_ */
