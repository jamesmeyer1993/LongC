#include "object/types.h"
#include "object/object.h"

struct Node_ Node {
  Node *prev;
  Node *next;
  void** data;
};

typedef struct LinkedList_ LinkedList {
  Object super; /* Extends from the type Object */
  int members;
  int limit;
  Node *head;
  Node *tail;
};

/* constructor */
LinkedList * initLinkedList(Object generic);

/* getters */
void* listHead(LinkedList * list);
void* listTail(LinkedList * list);
void* listGetAt(LinkedList * list, int position);
void* listFind(LinkedList * list, void * element);
int listCompare(LinkedList * list, LinkedList * to);

/* setters */
LinkedList * listAddAt(LinkedList * list, void * element, int position);
LinkedList * listAddtoFront(LinkedList * list, void * element);
LinkedList * listAddtoRear(LinkedList * list, void * element);
