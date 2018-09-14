#ifndef _STACKNODEH_
#define _STACKNODEH_

//#include "../../byte/byte.h"
#include "../obj.h"
#include "../type.h"

#ifndef T_NODE
  #define T_NODE 16
#endif

struct node
{
  struct node* next;
  struct node* prev;
  struct obj* data;
};

struct node newnode(struct node* p, struct node* q, struct obj* d);

struct obj node_toobj(struct node* src);

#endif
