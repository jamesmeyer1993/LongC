#ifndef _LISTH_
#define _LISTH_

#include "../obj.h"
#include "node.h"

#ifndef T_LIST
  #define T_LIST 17
#endif

struct list
{
  byte T;
  int size;
  int len;
};

struct list newlist(byte t)
{
  struct list l;
  l.T = t;
  l.size = 0;
  l.len = 0;
}

bool list_propertype(struct list* src, struct obj* t)
{
  if(t->T == src->T)
    return true;
  return false;
}

bool list_isempty(struct list* src)
{
  if(src->size == 0 && src->len == 0)
    return true;
  return false;
}

struct obj list_toobj(struct list* src)
{
  return newobj(T_LIST, src);
};

#endif
