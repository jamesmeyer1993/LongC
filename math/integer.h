#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "stdbool.h"
#include "primitives.h"

struct integer{
  u8* at;
  u8 base;
  u32 length;
  u32 capacity;
  bool is_negetive;
};

void init_integer(struct integer* self);

void init_integer1(struct integer* self, int a);

#endif
