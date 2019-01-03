#ifndef _LCTYPES_H_
#define _LCTYPES_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef float f32;
typedef int64_t i64;
typedef uint64_t u64;
typedef double f64;

RETURNABLE_TRAIT_H_(bool)
RETURNABLE_TRAIT_H_(char)
RETURNABLE_TRAIT_H_(i8)
RETURNABLE_TRAIT_H_(u8)
RETURNABLE_TRAIT_H_(i16)
RETURNABLE_TRAIT_H_(u16)
RETURNABLE_TRAIT_H_(i32)
RETURNABLE_TRAIT_H_(u32)
RETURNABLE_TRAIT_H_(f32)
RETURNABLE_TRAIT_H_(i64)
RETURNABLE_TRAIT_H_(u64)
RETURNABLE_TRAIT_H_(f64)

COMPARABLE_TRAIT_H_(bool)
COMPARABLE_TRAIT_H_(char)
COMPARABLE_TRAIT_H_(i8)
COMPARABLE_TRAIT_H_(u8)
COMPARABLE_TRAIT_H_(i16)
COMPARABLE_TRAIT_H_(u16)
COMPARABLE_TRAIT_H_(i32)
COMPARABLE_TRAIT_H_(u32)
COMPARABLE_TRAIT_H_(f32)
COMPARABLE_TRAIT_H_(i64)
COMPARABLE_TRAIT_H_(u64)
COMPARABLE_TRAIT_H_(f64)

#define REF(T) T##Ref

typedef struct ref {
  const void* self;
  const size_t tsize;
} Ref;

RETURNABLE_TRAIT_H_(Ref)
COMPARABLE_TRAIT_H_(Ref)

#define REF_TRAIT_H_(T) \
  typedef struct T##ref { \
    const T* self; \
  } REF(T);

#define DEREF( TYPE , POINTER ) *( (TYPE*)POINTER )

#endif /* _LCTYPES_H_ */
