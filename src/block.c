#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lang.h"
#include "block.h"

Block* NEW(Block)(const size_t capacity, const size_t type_size, bool resizable){
  assert(capacity > 0);

  Block* self = malloc(sizeof(Block));
  self->cap = capacity;
  self->tsize = type_size;
  self->resizable = resizable;

  size_t memlen = self->cap * self->tsize;
  self->bytes = malloc(memlen);
  self->used = malloc(sizeof(bool) * self->cap);

  memset(self->bytes, 0, memlen);
  memset(self->used, false, self->cap);

  return self;
}

void HEAP_FREE(Block)(Block* self){
  free(self->bytes);
  free(self->used);
  free(self);
}

Ref ALLOC(Block)(Block* self){

  u32 open_mem_index = 0;
  void* ref_ptr = NULL;
  for(u32 i = 0; i < self->cap; i++){
    ref_ptr = &self->bytes[(i * self->tsize)];

    if(self->used[i] == false){
      open_mem_index = i;
      break;
    }
  }

  const Ref cref = {self->tsize, ref_ptr};
  self->used[open_mem_index] = true;

  return cref;
}

bool FORGET(Block)(Block* self, Ref* disown){

  void* ref_ptr = NULL;
  for(u32 i = 0; i < self->cap; i++){
    ref_ptr = &self->bytes[(i * self->tsize)];

    if(memcmp(ref_ptr, disown->ptr, sizeof(void*)) == 0){
      self->used[i] = false;
    }
  }

  const Ref blank = {0, NULL};
  memcpy(disown, &blank, sizeof(Ref));
  return true;
}
