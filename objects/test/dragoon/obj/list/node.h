#ifndef _STACKNODEH_
#define _STACKNODEH_

#include "../obj.h"

#ifndef T_NODE
  #define T_NODE 16
#endif

struct node
{
  struct node* next;
  struct node* prev;
  struct obj* data;
};

// Preprocessor iterators
#define foreach_node(i, start) \
  assert( (start) != NULL ); \
  for(struct node* (i) = (start); (i) != NULL; (i) = (i)->next)

#define foreach_node_rev(i, start) \
  assert((start)!=NULL); \
  for(struct node* (i) = (start); (i) != NULL; (i) = (i)->prev)

// constructor
struct node* newnode(struct node* p, struct node* q, struct obj* d);

// destructor
void node_destroy(struct node* src);

struct obj* node_toobj(struct node* src);

#endif
