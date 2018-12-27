#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* new(Stack)(){
  struct stack* self = malloc(sizeof(struct stack));
  assert(self != NULL);

  self->len = 0;
  self->head = NULL;
  self->fn = NULL;
  return self;
}

Stack init(Stack)(){
  struct stack self;
  self.len = 0;
  self.head = NULL;
  self.fn = NULL;
  return self;
}

void PUSH(Stack,void)(Stack* self, const void* elem){

  assert(elem != NULL);

  if(self->head == NULL && self->len == 0){
    self->head = malloc(sizeof(struct node));
    assert(self->head != NULL);

    self->head->elem = elem;
    self->head->next = NULL;
    self->len++;
  }
  else {
    struct node* n = malloc(sizeof(struct node));
    assert(n != NULL);

    n->elem = elem;
    n->next = self->head;
    self->head = n;
    self->len++;
  }
}

struct node* POP(Stack,void)(Stack* self){

  if(self->head == NULL){
    return NULL;
  }
  else{
    struct node* give = self->head;
    self->head = self->head->next;

    assert(give != NULL);

    self->len--;
    return give;
  }
}

void* PEEK(Stack,void)(const Stack* self){

  if(self->head == NULL){
    return NULL;
  }
  else{
    return (void*)self->head->elem;
  }
}

ImplStack* new(ImplStack)(){
  ImplStack* self = malloc(sizeof(ImplStack));
  // self->new = &new(Stack);
  // self->init = &init(Stack);
  self->push = &PUSH(Stack,void);
  self->pop = &POP(Stack,void);
  self->peek = &PEEK(Stack,void);
  return self;
}

ImplStack init(ImplStack)(){
  ImplStack self;
  // self.new = &new(Stack);
  // self.init = &init(Stack);
  self.push = &PUSH(Stack,void);
  self.pop = &POP(Stack,void);
  self.peek = &PEEK(Stack,void);
  return self;
}
