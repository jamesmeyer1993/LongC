#include "stdlib.h"
#include "assert.h"

struct u8stack init_stack() {
  struct u8stack s;
  s.head = NULL;
  u32 length = 0;
  return s;
};

void u8stack_push(struct u8stack *self, u8 *elem){
  if(self->length == 0 && self->head == NULL){
    self->head = malloc(sizeof(u8node));
    self->head->elem = elem;
  }else{
    struct u8node *temp = malloc(sizeof(u8node));
    temp->elem = elem;
    temp->next = self->head;
    self->head = temp;
  }
  self->length++;
};

u8 u8stack_pop(struct u8stack *self){
  assert(self->length > 0 && self->head != NULL);
  u8 x = (u8*)(self->head->elem);
  struct u8node *temp = self->head->next;
  free(self->head);
  self->head = temp;
  self->length--;
  return x;
}

u8* u8stack_peek(struct u8stack *self){
  assert(self->length > 0 && self->head != NULL);
  return self->head->elem;
}
