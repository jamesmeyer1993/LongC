#include <stdlib.h>
#include <assert.h>

#include "../../obj.h"
#include "../list.h"
#include "../node.h"
#include "stack.h"

struct stack newstack(byte t)
{
  struct stack s;
  s.size = 0;
  s.len = 0;
  s.T = t;
  s.head = NULL;
  s.tail = NULL;
  return s;
}

void stack_push(struct stack* src, struct obj* elem)
{
  assert(src != NULL);
  assert(elem->T == src->T);

  if(src->len == 0 && src->head == NULL)
  {
    struct node n = newnode(NULL, NULL, elem);
    src->head = &n;
    src->len++;
    src->size+=sizeof(struct node);
  }
  else if(src->len == 1 && src->head != NULL && src->tail == NULL)
  {
    src->tail = src->head;
    struct node n = newnode(NULL, src->tail, elem);
    src->head = &n;
    src->len++;
    src->size+=sizeof(struct node);
  }
  else
  {
    struct node* temp;
    temp = src->head;
    struct node n = newnode(NULL, temp, elem);
    src->head = &n;
    src->len++;
    src->size+=sizeof(struct node);
  }
}

struct obj stack_pop(struct stack* src)
{
  assert(src->len > 0 && src->head != NULL);

  struct obj elem;
  elem.T = src->head->data->T;
  elem.self = src->head->data->self;

  src->head = src->head->next;
  src->len--;
  src->size-=sizeof(struct node);

  return elem;
}

struct obj stack_peek(struct stack* src)
{
  assert(src->len > 0 && src->head != NULL);

  struct obj elem;
  elem.T = src->head->data->T;
  elem.self = src->head->data->self;

  return elem;
}

struct list stack_tolist(struct stack* src)
{
  struct list l;
  l.T = src->T;
  l.len = src->len;
  l.size = src->size;
  return l;
}

struct obj stack_toobj(struct stack* src)
{
  struct obj o;
  o.T = T_STACK;
  o.self = src;
  return o;
}
