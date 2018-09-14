#include "node.h"
#include "byte.h"

// An Actual Stack for processing actaul data
struct Stack {
  struct Node head;
  struct Node tail;

  int elements;
}
