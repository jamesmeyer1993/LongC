#ifndef _TYPEH_
#define _TYPEH_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "obj.h"
#include "node.h"
#include "byte/byte.h"
#include "list.h"
#include "list/list.h"

#define T_NULL    0
#define T_OBJ     1
#define T_BYTE    2
#define T_BOOL    3
#define T_CHAR    4
#define T_SHORT   5
#define T_INT     6
#define T_LONG    7
#define T_FLOAT   8
#define T_DOUBLE  9

#define T_BYTESEQ 12
#define T_STRING  13

#define T_NODE    16
#define T_LIST    17
#define T_STACK   18
#define T_NLIST   19
#define T_DLIST   20

// talloc - type allocate
int talloc(byte T)
{
  switch(T)
  {
    case T_NULL:    return 0;
    case T_OBJ:     return sizeof(struct obj);
    case T_BYTE:    return sizeof(byte);
    case T_BOOL:    return sizeof(bool);
    case T_CHAR:    return sizeof(char);
    case T_SHORT:   return sizeof(short);
    case T_INT:     return sizeof(int);
    case T_LONG:    return sizeof(long);
    case T_FLOAT:   return sizeof(float);
    case T_DOUBLE:  return sizeof(double);
    case T_BYTESEQ: return sizeof(struct byteseq);
    case T_NODE:    return sizeof(struct node);
    case T_LIST:    return sizeof(struct list);
    case T_STACK:   return sizeof(struct stack);
    default:        return -1;
  }
}

#endif
