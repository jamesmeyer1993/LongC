#ifndef _LANG_H_
#define _LANG_H_

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

#define deref( TYPE , REF ) *( (TYPE*)REF )

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
/* Done --> we've typedef'd (24^2)=576 typle types. Out of 34 them, both types
are equal */

#endif /* _LANG_H_ */
