/* reference.h
ref is a struct that behaves like a generic wrapper for void pointers. A ref is
immutable. It can be used on the heap or the stack. The reason for the ref's
immutability is so it protect the memory location it points to. Once a reference
is created, it cannot be changed - only a memcpy can write over its data.
*/

#ifndef _POINTER_H_
#define _POINTER_H_

#include "longc/lang/primitives.h"

#define ref_t 32
#define mut_ref_t 33

typedef struct ref {
  const u8 type:8;
  const void* elem;
} ref;

typedef struct mut_ref {
  u8 type:8;
  void* elem;
} mut_ref;

#define deref( TYPE , REF ) *( (TYPE* )REF )

ref* new_ref(const u8 t, const void *e);

#endif
