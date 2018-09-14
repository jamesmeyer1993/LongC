#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "obj.h"

struct obj* newobj(byte t, void* s)
{
  struct obj* a = malloc(sizeof(struct obj));
  a->T = t;
  a->self = s;
  return a;
}

void obj_destroy(struct obj* src)
{
  assert(src != NULL);
  free(src);
}

bool obj_equals(struct obj* a, struct obj* b)
{

}

int obj_compareto(struct obj* a, struct obj* b)
{

}

char* obj_tostring(struct obj* src)
{

}

//struct byteseq* obj_bytesof(struct obj* src){}
