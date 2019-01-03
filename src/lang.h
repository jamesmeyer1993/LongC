#ifndef _LANG_H_
#define _LANG_H_

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*
Clearly defined primitive types are the standard of LongC. These types are
refered to as "universal" types in that their names transcend spoken languages,
programming languages, and their size is constant on all platforms.
*/
// typedef int8_t i8;
// typedef uint8_t u8;
// typedef int16_t i16;
// typedef uint16_t u16;
// typedef int32_t i32;
// typedef uint32_t u32;
// typedef float f32;
// typedef int64_t i64;
// typedef uint64_t u64;
// typedef double f64;

// RETURNABLE_TRAIT_H_(bool)
// RETURNABLE_TRAIT_H_(char)
// RETURNABLE_TRAIT_H_(i8)
// RETURNABLE_TRAIT_H_(u8)
// RETURNABLE_TRAIT_H_(i16)
// RETURNABLE_TRAIT_H_(u16)
// RETURNABLE_TRAIT_H_(i32)
// RETURNABLE_TRAIT_H_(u32)
// RETURNABLE_TRAIT_H_(f32)
// RETURNABLE_TRAIT_H_(i64)
// RETURNABLE_TRAIT_H_(u64)
// RETURNABLE_TRAIT_H_(f64)

// COMPARABLE_TRAIT_H_(bool)
// COMPARABLE_TRAIT_H_(char)
// COMPARABLE_TRAIT_H_(i8)
// COMPARABLE_TRAIT_H_(u8)
// COMPARABLE_TRAIT_H_(i16)
// COMPARABLE_TRAIT_H_(u16)
// COMPARABLE_TRAIT_H_(i32)
// COMPARABLE_TRAIT_H_(u32)
// COMPARABLE_TRAIT_H_(f32)
// COMPARABLE_TRAIT_H_(i64)
// COMPARABLE_TRAIT_H_(u64)
// COMPARABLE_TRAIT_H_(f64)

// #define DEREF( TYPE , POINTER ) *( (TYPE*)POINTER )
// #define REF(T) T##Ref
//
// typedef struct ref {
//   const void* self;
//   const size_t tsize;
// } Ref;
//
// RETURNABLE_TRAIT_H_(Ref)
// COMPARABLE_TRAIT_H_(Ref)
//
// #define REF_TRAIT_H_(T) \
//   typedef struct T##ref { \
//     const T* self; \
//   } REF(T);

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

#define LONGC_TRAIT_H_( T ) \
  \
  REF_TRAIT_H_(T) \
  RETURNABLE_TRAIT_H_(T) \
  RETURNABLE_TRAIT_H_(REF(T)) \
  COMPARABLE_TRAIT_H_(T) \
  \
  OPTION(REF(T)) NEW( T )(); \
  T INIT( T )(); \
  OPTION(REF(T)) CLONE( T )(const T* self); \
  RESULT(bool) HEAP_FREE( T )(T* self); \
  RESULT(bool) STACK_FREE( T )(T* self);

// new_from(...)
//  @accepts type to be allocated, type from, and source object
//  @returns pointer to type T_SELF allocated on heap
#define NEW_FROM( T_SELF , T_SRC ) new_##T_SELF##_from_##T_SRC
#define INIT_FROM( T_SELF , T_SRC ) init_##T_SELF##_from_##T_SRC

#define FROM_TRAIT_H_( T_SELF, T_SRC ) \
  OPTION(REF(T)) NEW_FROM(T_SELF, T_SRC)(const T_SRC *src); \
  OPTION(T_SELF) INIT_FROM(T_SELF, T_SRC)(const T_SRC *src);

#endif /* _LANG_H_ */
