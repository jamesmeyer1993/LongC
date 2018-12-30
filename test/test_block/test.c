#include "../../bin/lang.h"
#include "../../bin/block.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct dummy {
  bool is_dumb;
  u64 hash;
  u32 friends;
};

void print_bytes(Block* self){
  for(u32 i = 0; i < self->cap * self->tsize; i++){
    printf("%d", (u32)self->bytes[i]);
  }
  printf("\n");
}

i32 main(void){

  Block* dblock = NEW(Block)(5, sizeof(struct dummy), false);

  Ref r1 = ALLOC(Block)(dblock);
  Ref r2 = ALLOC(Block)(dblock);
  Ref r3 = ALLOC(Block)(dblock);

  assert(sizeof(void*) == sizeof(struct dummy*));

  struct dummy* dum = NULL;
  {
    memcpy(&dum, &r1.ptr, sizeof(void*));
    dum->is_dumb = true;
    dum->hash = 111;
    dum->friends = 2;
    print_bytes(dblock);
  }

  {
    memcpy(&dum, &r2.ptr, sizeof(void*));
    dum->is_dumb = true;
    dum->hash = 222;
    dum->friends = 3;
    print_bytes(dblock);
  }

  {
    memcpy(&dum, &r3.ptr, sizeof(void*));
    dum->is_dumb = true;
    dum->hash = 333;
    dum->friends = 4;
    print_bytes(dblock);
  }

  Ref r4 = ALLOC(Block)(dblock);
  Ref r5 = ALLOC(Block)(dblock);

  {
    memcpy(&dum, &r4.ptr, sizeof(void*));
    dum->is_dumb = true;
    dum->hash = 360;
    dum->friends = 29;
    print_bytes(dblock);
  }

  {
    memcpy(&dum, &r5.ptr, sizeof(void*));
    dum->is_dumb = false;
    dum->hash = 5280;
    dum->friends = 14;
    print_bytes(dblock);
  }

  assert(FORGET(Block)(dblock, &r5));
  printf("%d\n", (u32)r5.tsize);

  assert(FORGET(Block)(dblock, &r4));
  printf("%d\n", (u32)r4.tsize);

  assert(FORGET(Block)(dblock, &r3));
  printf("%d\n", (u32)r3.tsize);

  assert(FORGET(Block)(dblock, &r2));
  printf("%d\n", (u32)r2.tsize);

  assert(FORGET(Block)(dblock, &r1));
  printf("%d\n", (u32)r1.tsize);

  HEAP_FREE(Block)(dblock);
}
