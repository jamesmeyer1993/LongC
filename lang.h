#ifndef _LANG_H_
#define _LANG_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <longc/traits/trait.h>
#include <longc/traits/comparable.h>

// Additional, clearly define types provided by LongC
// Regular primitives - types
typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
typedef float f32;
typedef long i64;
typedef unsigned long u64;
typedef double f64;

// assign type id's
#define void_t  0
#define i8_t    1
#define u8_t    2
#define i16_t   3
#define u16_t   4
#define i32_t   5
#define u32_t   6
#define f32_t   7
#define i64_t   8
#define u64_t   9
#define f64_t   10
// done


// ref and mut_ref

/* ref
ref is a struct that behaves like a generic wrapper for void pointers. A ref is
immutable. It can be used on the heap or the stack. The reason for the ref's
immutability is so it protect the memory location it points to. Once a reference
is created, it cannot be changed - only a memcpy can write over its data.
*/
#define ref_t     11  // always assign a type id.
#define mut_ref_t 12  // this group begins at 32. It's easier to count groups
// of integers - ranges - rather than individuals. So the ref type begins at
// 32
typedef struct ref {
  const u32 type:32;    // <-- notice: 32 bytes are allocated here for the
  // various types. That means we've allocated space at least for 2^31
  // combinations.
  const void* src;
} ref;

/* mut_ref
A mutable form of the constant reference. Be careful with this type. Try to
use it only for periods where a variety of changes are being made and we're
avoiding compiler warnings. Eventually though, the mut_ref will need to be
copied back over to a const ref to maintain a proper coding pattern.*/
typedef struct mut_ref {
  u32 type:32;
  void* src;
} mut_ref;

#define deref( TYPE , REF ) *( (TYPE*)REF )

ref* new_ref(const u32 t, const void *e);

mut_ref* new_mut_ref(u32 t, void *e);

/* TUPLES
Generates types automatically for strong type'd programs.
An example tuple could be u32_
*/
#define _TUPLE_OF( T1 , T2 ) typedef \
struct T1 ## _ ## T2 { \
  const T1 a; \
  const T2 b; \
} T1 ## _ ## T2; \

#define DEF_TUPLES_LANG( T ) \
  _TUPLE_OF( T , u8 ) \
  _TUPLE_OF( T , i8 ) \
  _TUPLE_OF( T , u16 ) \
  _TUPLE_OF( T , i16 ) \
  _TUPLE_OF( T , u32 ) \
  _TUPLE_OF( T , i32 ) \
  _TUPLE_OF( T , f32 ) \
  _TUPLE_OF( T , u64 ) \
  _TUPLE_OF( T , i64 ) \
  _TUPLE_OF( T , f64 ) \
  _TUPLE_OF( T , ref )

/* This is basically a static for-each of the above */
DEF_TUPLES_LANG(i8)
DEF_TUPLES_LANG(u8)
DEF_TUPLES_LANG(u16)
DEF_TUPLES_LANG(i16)
DEF_TUPLES_LANG(u32)
DEF_TUPLES_LANG(i32)
DEF_TUPLES_LANG(f32)
DEF_TUPLES_LANG(u64)
DEF_TUPLES_LANG(i64)
DEF_TUPLES_LANG(f64)
DEF_TUPLES_LANG(ref)
/* Done --> we've typedef'd (24^2)=576 typle types. Out of 34 them, both types
are equal */

TRAIT( COMPARABLE, u8 )
TRAIT( COMPARABLE, i8 )
TRAIT( COMPARABLE, u16)
TRAIT( COMPARABLE, i16)
TRAIT( COMPARABLE, u32)
TRAIT( COMPARABLE, i32)
TRAIT( COMPARABLE, f32)
TRAIT( COMPARABLE, u64)
TRAIT( COMPARABLE, i64)
TRAIT( COMPARABLE, f64)
TRAIT( COMPARABLE , ref)


#endif /* _LANG_H_ */
