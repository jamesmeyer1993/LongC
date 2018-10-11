/* reference.h
ref is a struct that behaves like a generic wrapper for void pointers. A ref is
immutable. It can be used on the heap or the stack. The reason for the ref's
immutability is so it protect the memory location it points to. Once a reference
is created, it cannot be changed - only a memcpy can write over its data.
*/

#ifndef _REFERENCE_H_
#define _REFERENCE_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <longc/lang/primitives.h>

#define ref_t     32  // always assign a type id.
#define mut_ref_t 33  // this group begins at 32. It's easier to count groups
// of integers - ranges - rather than individuals. So the ref type begins at
// 32
typedef struct ref {
  const u32 type:32;    // <-- notice: 32 bytes are allocated here for the
  // various types. That means we've allocated space at least for 2^31
  // combinations.
  const void* src;
} ref;

// mut_ref
/*
A mutable form of the constant reference. Be careful with this type. Try to
use it only for periods where a variety of changes are being made and we're
avoiding compiler warnings. Eventually though, the mut_ref will need to be
copied back over to a const ref to maintain a proper coding pattern.
*/
typedef struct mut_ref {
  u32 type:32;
  void* src;
} mut_ref;

#define to_deref( TYPE , REF ) *( (TYPE*)REF )

ref* new_ref(const u32 t, const void *e);

mut_ref* new_mut_ref(u32 t, void *e);

#endif
