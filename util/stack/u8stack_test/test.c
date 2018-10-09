#include "longc/lang/primitives.h"
#include "u8stack.h"
#include <assert.h>
#include <stdlib.h>

int main(){

  const u8 c1 = 'h';
  const u8 c2 = 'e';
  const u8 c3 = 'l';
  const u8 c4 = 'o';

  struct u8stack stack = init_stack();

  u8stack_push(&stack, &c1);
  u8stack_push(&stack, &c2);
  u8stack_push(&stack, &c3);
  u8stack_push(&stack, &c3);
  u8stack_push(&stack, &c4);
  assert(stack.length == 5);

  u8 *ref = u8stack_peek(&stack);
  u8 ch = *(ref);
  assert(c4 == ch);

  for(int i = stack.length; i > -1; assert(stack.length == --i) ){
    ch = *(u8stack_pop(&stack));
    assert(ch != NULL);
  }

}
