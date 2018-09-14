#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "obj.h"

struct obj newobj(byte t, void* s)
{
  struct obj a;
  a.T = t;
  a.self = s;
  return a;
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

struct byteseq obj_bytesof(struct obj* src)
{

}
