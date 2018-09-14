#include <stdlib.h>
#include <assert.h>
#include "node.h"

struct node* newnode(struct node* p, struct node* q, struct obj* d)
{
  struct node* n = malloc(sizeof(struct node));
  n->prev = p;
  n->next = q;
  n->data = d;
  return n;
}

void node_destroy(struct node* src)
{
  assert(src != NULL);
  obj_destroy(src->data);
  free(src);
}

struct obj* node_toobj(struct node* src)
{
  return newobj(T_NODE, src);
}
