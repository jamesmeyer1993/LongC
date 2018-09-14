#ifndef _OBJH_
#define _OBJH_

#include <stdbool.h>

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

//#define SIZEOF_OBJ 16
typedef unsigned char byte;

struct obj
{
  byte T;
  void* self;
  int (*compareto)(struct obj* a, struct obj* b);
  bool (*equals)(struct obj* a, struct obj* b);
  void (*tostring)(struct obj* a, char* s);
};

#define OBJ struct obj

// Preprocessor iterators
#define endfor } \
  else{exit(EXIT_FAILURE);}

#define foreach_obj(elem, array, start, end) \
  if( (array) != NULL && (start) < (end) ){ \
    int i = (start); \
    for( struct obj* (elem) = ( struct obj* ) &(array)[i]; \
      i < (end); \
      (elem) = ( struct obj* ) &(array)[++i])

#define foreach_obj_rev(elem, array, start, end) \
  if( (array) != NULL && (start) > (end) ){ \
    int i = (start); \
    for( struct obj* (elem) = ( struct obj* ) &(array)[i]; \
      i >= (end); \
      (elem) = ( struct obj* ) &(array)[--i])

// Preprocessor constructors

// NEWOBJ - for creating a new object on the heap
#define NEWOBJ(name, type, ptr) \
  struct obj* (name) = malloc(sizeof(struct obj)); \
  assert( (name) != NULL); \
  (name)->T = (type); \
  (name)->self = (ptr); \
  (name)->compareto = &obj_compareto; \
  (name)->equals = &obj_equals; \
  (name)->tostring = &obj_tostring

// INITOBJ - for creating a new object on the stack
#define INITOBJ(name, type, ptr) \
  struct obj (name); \
  (name).T = (type); \
  (name).self = ptr; \
  (name).compareto = &obj_compareto; \
  (name).equals = &obj_equals; \
  (name).tostring = &obj_tostring;

// constructor
struct obj* newobj(byte t, void* s);

// destructor
#define OBJ_DESTROY(name) \
  assert( (name) != NULL); \
  free( (name) )

void obj_destroy(struct obj* src);

bool obj_equals(struct obj* a, struct obj* b);

int obj_compareto(struct obj* a, struct obj* b);

void obj_tostring(struct obj* src, char* s);

//struct byteseq* obj_bytesof(struct obj* src);

//struct byteseq* bytesof(struct obj* src);

#endif
