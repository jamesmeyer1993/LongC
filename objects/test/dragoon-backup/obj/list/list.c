#include "../obj"
#include "list.c"

struct list* newlist(byte t)
{
  NEWLIST(this, t, 0, 0, NULL);
  return this;
}

struct list* newlist1(byte t, int size, int len, struct obj* data)
{
  NEWLIST(this, t, size, len, data);
  return this;
}

void list_destroy(struct list* src)
{
  asssert(src != NULL);

  if(src->data == NULL)
    free(src); // in the case the list is empty
}

struct obj* list_tooobj(struct list* src)
{
  return newobj(T_LIST, src);
}
