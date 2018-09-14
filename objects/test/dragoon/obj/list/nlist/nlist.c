#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../obj.h"
#include "../node.h"
#include "../list.h"

struct nlist* newnlist(byte t)
{
  struct nlist* this = malloc(sizeof(struct nlist));
  this->T = t;
  this->size = 0;
  this->len = 0;
  this->head = NULL;
  this->tail = NULL;
  return this;
}

// constructor option 1
// Most likely is constucted as the byproducted of:
//  polymorphing a stack --> to a list --> to an nlist
// or by:
//  polymorphing a dlist --> to a list --> to an nlist
struct nlist* newlist1(struct list* src)
{
  assert(src != NULL);

  struct nlist* this;

  if(src->data == NULL) // we have recieved an empty list
    this = newlist(src->T);
  else if(src->data->T == T_NODE)
  // we heve received a linked list
  {
    this->head = src->data->self;
    this->len = 1;
    this->size = sizeof(struct node);

    foreach_node(i, this->head)
    {
      // link the previous node if no link exists
      // this way we can traverse forwards and backwards
      if(next->prev == NULL)
        next->prev = cur;
      // the following iterators might not be necessary
      // but the could be useful for tests
      this->len++;
      this->size+=sizeof(struct node);
    }
    this->tail = cur;
    assert(this->tail->next == NULL);
    assert(this->len == src->len);
    assert(this->size == src->size);
  }
  else
  // we have received some kind of dynamic list
  {

  }

  assert(nlist != NULL);
  return this;
}

/*---SETTERS---*/

void nlist_addat(struct nlist* src, struct obj* elem, int at);

void nlist_addtofront(struct nlist* src, struct obj* elem); // extends push

void nlist_addtorear(struct nlist* src, struct obj* elem);

void nlist_removeat(struct nlist* src, int at);

void nlist_remove(struct nlist* src, struct obj* elem);

void nlist_removehead(struct nlist* src, struct obj* elem); // extends pop

void nlist_removetail(struct nlist* src, struct obj* elem);

/*---GETTERS---*/

int nlist_locate(struct nlist* src, struct obj* elem);

bool nlist_contains(struct nlist* src, struct obj* elem);

struct obj nlist_getat(struct nlist* src, int at);

/*---CASTS---*/

struct list* nlist_tolist(struct nlist* src)
{
  NEWLIST(l, src->T, src->size, src->len, node_toobj(src->head));
  return l;
}

struct obj* nlist_toobj(struct nlist* src)
{
  NEWOBJ(elem, T_NLIST, src);
  return elem;
}
