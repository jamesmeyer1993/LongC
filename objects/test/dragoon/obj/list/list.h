#ifndef _LISTH_
#define _LISTH_

#include <stdbool.h>
#include "../obj.h"

#ifndef T_LIST
  #define T_LIST 17
#endif

struct list
{
  byte T;
  int size;
  int len;
  struct obj* data;
};

#define NEWLIST(name, type, size, len, data) \
  struct list* (name) = malloc(sizeof(struct list)); \
  (name)->T = (type); \
  (name)->size = (size); \
  (name)->len = (len); \
  (name)->data = (data)

struct list* newlist(byte t);

void list_destroy(struct list* src);

struct obj* list_toobj(struct list* src);

#endif
