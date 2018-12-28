#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* NEW(Stack)(){
  struct stack* self = malloc(sizeof(struct stack));
  assert(self != NULL);

  self->len = 0;
  self->head = NULL;
  //self->fn = methods;
  return self;
}

Stack INIT(Stack)(){
  struct stack self;
  self.len = 0;
  self.head = NULL;
  //self.fn = methods;
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
    assert(give != NULL && give->elem != NULL);

    self->head = self->head->next;
    self->len--;
    return give;
  }
}

struct node* PEEK(Stack,void)(const Stack* self){

  if(self->head == NULL){
    return NULL;
  }
  else{
    return self->head;
  }
}

// ImplStack* NEW(ImplStack)(){
//   ImplStack* self = malloc(sizeof(ImplStack));
//   // self->NEW = &NEW(Stack);
//   // self->INIT = &INIT(Stack);
//   self->push = &PUSH(Stack,void);
//   self->pop = &POP(Stack,void);
//   self->peek = &PEEK(Stack,void);
//   return self;
// }
//
// ImplStack INIT(ImplStack)(){
//   ImplStack self;
//   // self.NEW = &NEW(Stack);
//   // self.INIT = &INIT(Stack);
//   self.push = &PUSH(Stack,void);
//   self.pop = &POP(Stack,void);
//   self.peek = &PEEK(Stack,void);
//   return self;
// }
