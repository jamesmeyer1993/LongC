#ifndef _OBJH_
#define _OBJH_

#include "type.h"
#include "byte/byte.h"

#ifndef T_NULL
  #define T_NULL 0
#endif

#ifndef T_OBJ
  #define T_OBJ 1
#endif

#define SIZEOF_OBJ 16

struct obj
{
  byte T;
  void* self;
};

struct obj newobj(byte t, void* s);

bool obj_equals(struct obj* a, struct obj* b);

int obj_compareto(struct obj* a, struct obj* b);

char* obj_tostring(struct obj* src);

struct byteseq obj_bytesof(struct obj* src);

struct byteseq bytesof(struct obj* src);

#endif
