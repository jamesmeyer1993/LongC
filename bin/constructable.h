#ifndef _CONSTRUCTABLE_H_
#define _CONSTRUCTABLE_H_

#include <stdbool.h>
#include "lang.h"

#define implements_constructable( T ) T ## _implements_constructable

#define new( T ) new_ ## T ## _()

#define new_from( T , SRC ) new_ ## T ## _from_( SRC )

#define new_with_capacity( T , CAP ) new_ ## T ## _with_capacity_( CAP )

#define init( T ) init_ ## T ## _()

#define init_from( T , SRC ) init_ ## T ## _from_( SRC )

#define init_with_capacity( T , CAP ) init_ ## T ## _with_capacity_( CAP )

#define heap_free( T , SELF ) heap_free_ ## T ## _( SELF )

#define stack_free( T , SELF ) stack_free_ ## T ## _( SELF )

/*
#define CONSTRUCTABLE_TRAIT( T ) \
  \
  u32 T ## _implements_constructable(); \
  \
  T* new_ ## T ##(); \
  \
  T init_ ## T ##(); \
  \
  bool heap_free_ ## T ##( T* self ); \
  \
  bool stack_free_ ## T ##( T* self );
*/
#endif // _CONSTRUCTABLE_H_
