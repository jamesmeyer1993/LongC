#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include "lang.h"

#define push(T_SELF, T_ELEM) T_ELEM##T_SELF##_push

#define pop(T_SELF, T_ELEM) T_ELEM##T_SELF##_pop

#define peek(T_SELF, T_ELEM) T_ELEM##T_SELF##_peek

struct node {
  struct node* next;
  void* elem;
};

typedef struct stack {
  struct node* head;
  size_t len;
  struct impl_stack* fn;
} Stack;

typedef struct impl_stack {
  Stack* (*new)();
  Stack (*init)();
  void (*push)(struct stack*, const void*);
  void* (*pop)(struct stack*);
  const void* (*peek)(struct stack*);
} ImplStack;

Stack* new(Stack)();

Stack init(Stack)();

void push(Stack,void)(Stack* self, const void* elem);

void* pop(Stack,void)(Stack* self);

const void* peek(Stack,void)(Stack* self);

ImplStack* new(ImplStack)();

ImplStack init(ImplStack)();

/*
#define push(T_SELF, SELF, T_ELEM, ELEM) T_ELEM##T_SELF##_push(SELF, ELEM)

#define pop(T_SELF, SELF, T_ELEM) T_ELEM##T_SELF##_pop(SELF)

#define peek(T_SELF, SELF, T_ELEM) T_ELEM##T_SELF##_peek(SELF)

#define STACK_H( T ) \
  \
  struct ##T##Node { \
    T##Node* next; \
    T* elem; \
  }
  \
  T##Node* new(T##Node); \
  \
  struct ##T##Stack { \
    T##Node* head; \
    size_t len; \
  }\
  \
  T##Stack* new(T##Stack); \
  \
  T##Stack* new_from(T##Stack, T , const T* list); \
  \
  T##Stack init(T##Stack); \
  \
  T##Stack init_from(T##Stack, T , const T* list); \
  \
  void push(T##Stack, Stack* self, T, T* elem); \
  \
  void pop(T##Stack, Stack* self, T); \
  \
  void peek(T##Stack, Stack* self, T);


#define STACK_C( T ) \
  \
  T##Stack new(T##Stack){ \
    T##Stack* self = malloc(sizeof(T##Stack)); \
    self->head = NULL; \
    self->len = 0; \
    return self; \
  } \
  \
  T##Stack new_from(T##Stack, T , const T##_size_t list){ \
    assert(list.elem != NULL); \
    assert(list.len > 0); \
    \
    T##Stack* self = malloc(sizeof(T##Stack)); \
    self->head = NULL; \
    self->len = 0; \
    \
    for(u32 i = 0; i < list.len; i++){ \
      push(T##Stack, self, T, list.elem[i]); \
      self->len++; \
    } \
    \
    return self; \
  } \
  \
  T##Stack init(T##Stack){ \
    T##Stack self; \
    self.head = NULL; \
    self.len = 0; \
    return self; \
  } \
  \
  T##Stack init_from(T##Stack, T , const T##_size_t list){ \
    assert(list.elem != NULL); \
    assert(list.len > 0); \
    \
    T##Stack self; \
    self.head = NULL; \
    self.len = 0; \
    \
    for(u32 i = 0; i < list.len; i++){ \
      push(T##Stack, self, T, list.elem[i]); \
      self.len++; \
    } \
    \
    return self; \
  } \
  \
  bool heap_free(T##Stack, Stack* self); \
  \
  bool stack_free(T##Stack, Stack* self); \
  \
  void push(T##Stack, Stack* self, T, T* elem){} \
  \
  void pop(T##Stack, Stack* self, T){} \
  \
  void peek(T##Stack, Stack* self, T){}
*/

#endif /* _STACK_H_ */
