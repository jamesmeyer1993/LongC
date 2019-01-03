#ifndef _LONGC_H_
#define _LONGC_H_

#include <stdbool.h>
#include "lctypes.h"
#include "returnable.h"
#include "comparable.h"

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

#endif /* _LONGC_H_ */
