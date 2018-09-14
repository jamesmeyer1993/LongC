#include "node.h"

struct node newnode(struct node* p, struct node* q, struct obj* d)
{
  struct node n;
  n.prev = p;
  n.next = q;
  n.data = d;
  return n;
}

struct obj node_toobj(struct node* src)
{
  return newobj(T_NODE, src);
}
