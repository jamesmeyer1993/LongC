#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <stdbool.h>
#include <stdlib.h>
#include "lang.h"

typedef struct ref {
  const size_t tsize;
  const void* ptr;
} Ref;

typedef struct block {
  i8* bytes;
  bool* used;
  size_t tsize;
  size_t cap;
  bool resizable;
} Block;

#define ALLOC( T ) T##_alloc

#define FORGET( T ) T##_forget

Block* NEW(Block)(const size_t capacity, const size_t type_size, bool resizable);

void HEAP_FREE(Block)(Block* self);

Ref ALLOC(Block)(Block* self);

bool FORGET(Block)(Block* self, Ref* disown);

#endif /* _BLOCK_H_ */
