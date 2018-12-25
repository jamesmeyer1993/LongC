// Ref and mRef

/* Ref
Ref is a struct that behaves like a generic wrapper for void pointers. A ref is
immutable. It can be used on the heap or the stack. The reason for the ref's
immutability is so it protect the memory location it points to. Once a reference
is created, it cannot be changed - only a memcpy can write over its data.
*/

// of integers - ranges - rather than individuals. So the ref type begins at
// 32
typedef struct ref {
  const u32 type:32;    // <-- notice: 32 bytes are allocated here for the
  // various types. That means we've allocated space at least for 2^31
  // combinations.
  const void* src;
} Ref;

/* mRef
A mutable form of the constant reference. Be careful with this type. Try to
use it only for periods where a variety of changes are being made and we're
avoiding compiler warnings. Eventually though, the mRef will need to be
copied back over to a const ref to maintain a proper coding pattern.*/
typedef struct mref {
  u32 type:32;
  void* src;
} mRef;

#define deref( TYPE , REF ) *( (TYPE*)REF )

Ref* new_ref(const u32 t, const void *e);

mRef* new_mRef(u32 t, void *e);
