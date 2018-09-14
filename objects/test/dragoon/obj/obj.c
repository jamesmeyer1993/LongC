#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
  OBJ_DESTROY(src);
}

bool obj_equals(struct obj* a, struct obj* b)
{
  if(a != b)
  {
    if(a->T != b->T){return false;}
    else if(a->self == b->self){return true;}
    else
    {
      struct obj* ref = (struct obj*)a->self;
      return ref->equals(a->self, b->self);
    }
  }
  return true;
}

int obj_compareto(struct obj* a, struct obj* b)
{
  assert(a != NULL && b != NULL);
  if(a != b)
  {
    if(a->T == T_OBJ && b->T == T_OBJ)
    {
      if(a->self > b->self){return 1;}
      else if(a->self == b->self){return 0;}
      else{return -1;}
    }
    else
    {
      assert(a->self != NULL);
      struct obj* ref = (struct obj*)(a->self);
      return ref->compareto(a->self, b->self);
    }
  }
  return 0;
}

void obj_tostring(struct obj* src, char* out)
{
  assert(src != NULL);
  if(src->T == T_OBJ)
  {
    //"obj:{T=___,self=________}"
    strcpy(out, "obj:{T=,self=");

    union cast
    {
      unsigned long long ptr; // 8 bytes
      char string[8];
    };
    union cast to;
    unsigned long long* trans = (unsigned long long*)src->self;
    to.ptr = trans;

    strcpy(out, to.string);
    strcpy(out, "}");
  }
  else
  {
    struct obj* ref = (struct obj*)src->self;
    ref->tostring(src->self, out);
  }
}

//struct byteseq* obj_bytesof(struct obj* src){}
