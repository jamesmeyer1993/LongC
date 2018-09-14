#include "object/types.h"
#include "object/object.h"
#include "linkedlist.h"

#include <stdio.h> /* debug */
#include <ctype.h>

LinkedList * initLinkedList(Object * generic){
  LinkedList list = (LinkedList*)malloc(sizeof(LinkedList));
  list->super = generic;
  list->members = 0;

  /* debug */printf("LinkedList instantiated.\n\tExtends = %s\n\tSize = %d\n\t\n", typeof(super) ;
};

void* listHead(LinkedList * list);

void* listTail(LinkedList * list);

void* listGetAt(LinkedList * list, int position);

int* listFind(LinkedList * list, void * element);

int* listCompare(LinkedList * list, LinkedList * to){
  return 0;
};

LinkedList * listAddAt(LinkedList * list, void * element, int position){
  /* instantiate the node and allocate memory */
  Node n = (Node*)malloc(sizeof(Node));
  n->data=(void*)malloc(sizeof(element));
  /* then determine where to place the node */
  if(list->members-1 < position)
};

LinkedList * listAddtoFront(LinkedList * list, void * element);

LinkedList * listAddtoRear(LinkedList * list, void * element);
