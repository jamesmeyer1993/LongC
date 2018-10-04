#ifndef _U8_STACK_H_
#define _U8_STACK_H_

struct u8node {
  struct u8node *next;
  u8 *elem;
}

struct u8stack {
  u8node *head;
  u32 length;
};

struct u8stack init_stack();

void u8stack_push(struct u8stack *self, u8 *elem);

u8 u8stack_pop(struct u8stack *self);

u8* u8stack_peek(struct u8stack *self);

#endif
