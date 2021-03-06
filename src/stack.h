#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include "lang.h"

#define PUSH(T_SELF, T_OWNED) T_OWNED##T_SELF##_push
#define POP(T_SELF, T_OWNED) T_OWNED##T_SELF##_pop
#define PEEK(T_SELF, T_OWNED) T_OWNED##T_SELF##_peek

#define STACK_TRAIT_H_(T_SELF, T_OWNED) \
  void PUSH(T_SELF, T_OWNED)(T_SELF* self, T_OWNED* elem); \
  T_OWNED* POP(T_SELF, T_OWNED)(T_SELF* self); \
  T_OWNED* PEEK(T_SELF, T_OWNED)(T_SELF* self);

struct node {
  struct node* next;
  const void* elem;
};

typedef struct stack {
  struct node* head;
  size_t len;
  //struct impl_stack* fn;
} Stack;

Stack* NEW(Stack)();

Stack INIT(Stack)();

void PUSH(Stack,void)(Stack* self, const void* elem);

struct node* POP(Stack,void)(Stack* self);

struct node* PEEK(Stack,void)(const Stack* self);

#endif /* _STACK_H_ */
