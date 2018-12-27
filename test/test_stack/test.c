#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../bin/lang.h"
#include "../../bin/stack.h"

i32 main(void){

  ImplStack fn = init(ImplStack)();

  u32 a = 2;
  u32 b = 3;
  u32 c = 5;
  u32 d = 7;
  u32 e = 11;

  Stack vstack = init(Stack)(&fn);

  fn.push(&vstack, &a);
  fn.push(&vstack, &b);
  fn.push(&vstack, &c);
  fn.push(&vstack, &d);
  fn.push(&vstack, &e);

  assert(vstack.len == 5);
  struct node* forget = NULL;

  {
    forget = fn.peek(&vstack);
    assert(forget != NULL);

    assert(e == deref(u32, forget->elem));
    forget = NULL;
  }

  {
    forget = fn.pop(&vstack);
    assert(forget != NULL);

    printf("Stack len: %d\n", (u32)vstack.len);
    assert( e == deref(u32, forget->elem) && vstack.len == 4);
    free(forget);
  }

  {
    forget = fn.pop(&vstack);
    assert(forget != NULL);

    printf("Stack len: %d\n", (u32)vstack.len);
    assert( d == deref(u32, forget->elem) && vstack.len == 3);
    free(forget);
  }

  {
    forget = fn.pop(&vstack);
    assert(forget != NULL);

    printf("Stack len: %d\n", (u32)vstack.len);
    assert( c == deref(u32, forget->elem) && vstack.len == 2);
    free(forget);
  }

  {
    forget = fn.pop(&vstack);
    assert(forget != NULL);

    printf("Stack len: %d\n", (u32)vstack.len);
    assert( b == deref(u32, forget->elem) && vstack.len == 1);
    free(forget);
  }

  {
    forget = fn.pop(&vstack);
    assert(forget != NULL);

    printf("Stack len: %d\n", (u32)vstack.len);
    assert( a == deref(u32, forget->elem)  && vstack.len == 0);
    free(forget);
  }

  return 0;
}
