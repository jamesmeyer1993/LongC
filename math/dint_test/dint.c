#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "dint.h"

// initializers
struct dint init_dint(){
  struct dint n;
  n.at = malloc(1024);
  n.length = 0;
  n.capacity = 1024;
  return n;
};

bool dint_equals(struct dint *self, struct dint *other){

  assert(
    (self->length <= self->capacity)
    && (other->length) <= (other->capacity)
  );

  if(self->length != other->length){
    return false;
  }else{
    for(u32 i = 0; i < self->length; i++){
      if(self->at[i] != other->at[i]){
        return false;
      }
    }
  }
  return true;
}

i32 dint_compare(struct dint *self, struct dint *other){
  assert(
    (self->length <= self->capacity)
    && (other->length) <= (other->capacity)
  );

  // compare lengths
  if(self->length > other->length){
    return 1;
  }
  else if(self->length < other->length){
    return -1;
  }
  // else compare values
  for(u32 i = 0; i < self->length; i++){
    if(self->at[i] > other->at[i]){
      return 1;
    }
    else if(self->at[i] < other->at[i]){
      return -1;
    }
  }
  // else they're equal
  return 0;
}

void dint_set(struct dint *self, u8 *dgst, u32 dgst_len){

  assert(dgst_len < self->capacity);

  for(u32 i = 0; i < dgst_len; i++){
    self->at[i] = dgst[i];
  }
  for(u32 i = dgst_len + 1; i < self->capacity; i++){
    self->at[i] = 0;
  }

  self->length = dgst_len;
}

void dint_print_ints(struct dint *self){
  printf("{");
  for(u32 i = 0; i < self->length; i++){
    printf("%d,", self->at[i]);
  }
  printf("}\n");
}
