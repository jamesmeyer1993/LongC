#include "..type/types.h"

typedef ArrayList_ {
  byte* data;
  type t;
  int size;
  int length;
} ArrayList;

ArrayList * initArrayList(type t, int s);
