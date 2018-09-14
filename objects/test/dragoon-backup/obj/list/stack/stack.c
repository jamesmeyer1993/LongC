#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../../obj.h"
#include "../list.h"
#include "../node.h"
#include "stack.h"

struct stack* newstack(byte t)
{
  struct stack* s = malloc(sizeof(struct stack));
  s->T = t;
  s->size = 0;
  s->len = 0;
  s->head = NULL;
  s->tail = NULL;
  return s;
}

void stack_destroy(struct stack* src)
{
  assert(src != NULL);

  if(src->len == 1)
    node_destroy(src->head);
  else if(src->len > 1);
  {
    int frees = src->len;
    for(int i = 0; i < frees; i++)
      obj_destroy(stack_pop(src));
    /*
    while(src->len != 0){
      struct obj* destroyable = stack_pop(src);
      obj_destroy(destroyable);
    }*/
  }
  free(src);
}

void stack_push(struct stack* src, struct obj* elem)
{
  assert(src != NULL);
  assert(elem->T == src->T);

  if(src->len == 0 && src->head == NULL)
    src->head = newnode(NULL, NULL, elem);
  else if(src->len == 1 && src->head != NULL && src->tail == NULL)
  {
    src->tail = src->head;
    src->head = newnode(NULL, src->tail, elem);
    src->tail->prev = src->head;
  }
  else
  {
    struct node* temp;
    temp = src->head;
    src->head = newnode(NULL, temp, elem);
    temp->prev = src->head;
  }
  src->len++;
  src->size+=sizeof(struct node);
}

struct obj* stack_pop(struct stack* src)
{
  assert(src->len > 0 && src->head != NULL);

  struct obj* elem = src->head->data;
  struct node* destroyable = src->head;

  if(src->len > 1){
    src->head = src->head->next;
    src->head->prev = NULL;
  }
  src->len--;
  src->size-=sizeof(struct node);
  free(destroyable);
  printf("DEBUG: successful pop\n");
  return elem;
}

struct obj* stack_peek(struct stack* src)
{
  assert(src->len > 0 && src->head != NULL);
  return src->head->data;
}

struct list* stack_tolist(struct stack* src)
{
  struct list* l = malloc(sizeof(struct list));
  l->T = src->T;
  l->len = src->len;
  l->size = src->size;
  l->data = node_toobj(src->head);
  return l;
}

struct obj* stack_toobj(struct stack* src)
{
  return newobj(T_STACK, src);
}
