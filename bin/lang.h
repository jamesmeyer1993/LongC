#ifndef _LANG_H_
#define _LANG_H_

#include <stdbool.h>

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

#define DEREF( TYPE , REF ) *( (TYPE*)REF )

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

//  *   *   *   *                          *    *   *
//    *   *   * Generic Functions and Traits  *   *   *
//  *   *   *   *                          *    *   *

// new( T )
//  @accepts type to be allocated on heap
//  @returns pointer to type T allocated on heap
#define NEW( T ) new_##T

#define INIT( T ) init_##T

// clone(...)
//  @accepts type T, which is the type of SELF.
//  @returns a full copy of the supplied type
#define CLONE( T ) clone_##T

#define HEAP_FREE( T ) heap_free_##T

#define STACK_FREE( T ) stack_free_##T

// This is the shorthand for calling the comparable function
#define CMPR( T ) T##_cmpr

// This is the shorthand for calling the equals function
#define EQ( T ) T##_eq

#define LONGC_TRAIT_H_( T ) \
  T* NEW( T )(); \
  T INIT( T )(); \
  T* CLONE( T )(const T* self); \
  void HEAP_FREE( T )(T* self); \
  void STACK_FREE( T )(T* self); \
  i32 CMPR( T )(const T* self, const T* other); \
  bool EQ( T )(const T* self, const T* other);
  //
  // String* NEW(String)();
  // String INIT(String)();
  // String* CLONE(String)(const String* self);
  // void HEAP_FREE(String)(String* self);
  // void STACK_FREE(String)(String* self);
  // i32 CMPR(String)(const String* self, const String* other);
  // bool EQ(String)(const String* self, const String* other);

// new_from(...)
//  @accepts type to be allocated, type from, and source object
//  @returns pointer to type T_SELF allocated on heap
#define NEW_FROM( T_SELF , T_SRC ) new_##T##_from_##T_SRC

#define INIT_FROM( T_SELF , T_SRC ) init_##T##_from_##T_SRC

#define FROM_TRAIT_H_( T_SELF, T_MACRO , T_ACTUAL) \
  T_SELF* NEW_FROM( T_SELF , T_SRC)(T_ACTUAL src); \
  T_SELF* INIT_FROM( T_SELF , T_SRC)(T_ACTUAL src);

#define CONTAINS( T ) T##_contains

#define INDEX_OF( T ) T##_index_of

#define STARTS_WITH( T ) T##_starts_with

#define ENDS_WITH( T ) T##_ends_with

#define RESIZE( T ) T##is_resize

#define NEW_WITH_CAPACITY( T ) new_##T##_with_capacity

#define INIT_WITH_CAPACITY( T ) init_##T##_with_capacity

#define COLLECTION_TRAIT_( T , INT_CAP , T_OWNED ) \
  T* NEW_WITH_CAPACITY(T)(size_t INT_CAP); \
  T INIT_WITH_CAPACITY(T)(size_t INT_CAP); \
  bool CONTAINS(T)(T* self, T* item); \
  u32 INDEX_OF(T)(T* self, T* item); \
  bool STARTS_WITH(T)(T* self, T* item); \
  bool ENDS_WITH(T)(T* self, T* item);

// approx(type, self, other, degree)
//  @returns 1 or 0 - true or false.
//  approx is to behave similarly to eq, but with a range of difference between
//  @self and @other.
/*  The following examples can apply to the following types:

    approx(f64, 3.145678, 3.145899, 3) -> returns true

    approx(u32, 512, 530, 2) -> returns true

    approx(string,
      new_string_from("hello world"),
      new_string_from("hello WORLD"), 5) -> returns true because there are 5
      equal elements

    approx(string,
      new_string_from("hello world!"),
      new_string_from("hello WORLD!"), 50%)
      -> return true because the strings share 50% of the same elements
*/
#define APPROX( T ) T##_approx

#endif /* _LANG_H_ */
