#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* new(Stack)(){
  struct stack* self = malloc(sizeof(struct stack));
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

  if(self->head == NULL){
    struct node* n = malloc(sizeof(struct node));
    n->elem = elem;
    n->next = NULL;
    self->len++;
  } else {
    struct node* n = malloc(sizeof(struct node));
    n->elem = elem;
    n->next = self->head;
    self->head = n;
    self->len++;
  }
}

void* POP(Stack,void)(Stack* self){

  if(self->head == NULL){
    return NULL;
  }
  else{
    void* e = NULL;
    memcpy(e, self->head->elem, sizeof(void*));

    struct node* forget = self->head;
    self->head = self->head->next;
    free(forget);

    self->len--;
    return e;
  }
}

const void* PEEK(Stack,void)(Stack* self){

  if(self->head == NULL){
    return NULL;
  }
  else{
    return self->head->elem;
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
