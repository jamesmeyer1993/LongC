#ifndef _LANG_H_
#define _LANG_H_

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*
Clearly defined primitive types are the standard of LongC. These types are
refered to as "universal" types in that their names transcend spoken languages,
programming languages, and their size is constant on all platforms.
*/
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

#define OPTION(T) Option_##T      // Can be, exclusively, some or none
#define SOME(T) some_##T          // Constructs an option with some item
#define NONE(T) none_##T          // Constructs an option with no item
#define HAS_SOME(T) has_some_##T  // Checks for some
#define HAS_NONE(T) has_none_##T  // Checks for none

/* OPTION_H_(T)
The generic type header for the option type. This header implements the above
definitions as function names. These functions include:
  1. Some(T)(@accepts: T) -> @returns: Option(T)
  2. None(T)(@accepts: void/nothing) -> @returns: Option(T)
  3. has_some(T)(@accepts: Option(T)) -> @returns: bool
  4. has_none(T)(@accepts: Option(T)) -> @returns: bool
*/
#define OPTION_H_(T) \
  typedef struct option_##T { \
    T some; \
    bool none; \
  } OPTION(T); \
  \
  OPTION(T) SOME(T)(const T some); \
  OPTION(T) NONE(T)(void); \
  bool HAS_NONE(T)(const OPTION(T) op); \
  bool HAS_SOME(T)(const OPTION(T) op);

/* OPTION_C_(T)
The generic type C complement for OPTION_H_(T). Because of the generic nature of
the Option type, this macro is provided so the exact behavior of the option type
may be implemented for all types that utilize the OPTION_H_(T).
*/
#define OPTION_C_(T) \
  OPTION(T) SOME(T)(const T some){ \
    OPTION(T) self; \
    memcpy(&self.some, &some, sizeof(T)); \
    self.none = false; \
    return self; \
  } \
  \
  OPTION(T) NONE(T)(void){ \
    OPTION(T) self; \
    memset(&self.some, (i32)'\0', sizeof(T)); \
    self.none = true; \
    return self; \
  } \
  \
  bool HAS_NONE(T)(const OPTION(T) op){ \
    T none; \
    size_t tsize = sizeof(T); \
    memset(&none, (i32)'\0', tsize); \
    if(op.none && memcmp(&none, &op.some, tsize) == 0){ \
      return true; \
    } \
    return false; \
  } \
  \
  bool HAS_SOME(T)(const OPTION(T) op){ \
    return !HAS_NONE(T)(op); \
  }

#define RESULT(T) Result_##T  // Can be, exclusively, ok or err
#define OK(T) ok_##T          // Constructs a result with an ok of T
#define ERR(T) err_##T        // Constructs a result with an err code
#define IS_OK(T) is_ok_##T    // Checks if a result is ok
#define IS_ERR(T) is_err_##T  // Checks if a result is an err

/* RESULT_H_(T)
The generic type header for the option type. This header implements the above
definitions as function names. These functions include:
  1. OK(T)(@accepts: T) -> @returns: RESULT(T)
  2. ERR(T)(@accepts: void/nothing) -> @returns: RESULT(T)
  3. IS_OK(T)(@accepts: RESULT(T)) -> @returns: bool
  4. IS_ERR(T)(@accepts: RESULT(T)) -> @returns: bool
*/
#define RESULT_H_(T) \
  typedef struct result_##T { \
    T ok; \
    i32 err; \
  } RESULT(T); \
  \
  RESULT(T) OK(T)(const T ok); \
  RESULT(T) ERR(T)(const i32 err); \
  bool IS_ERR(T)(const RESULT(T) op); \
  bool IS_OK(T)(const RESULT(T) op);

/* RESULT_C_
The C complement for RESULT_H_ that generates the generic functions, OK(T),
ERR(T), IS_OK(T), IS_ERR(T).
*/
#define RESULT_C_(T) \
  RESULT(T) OK(T)(const T ok){ \
    RESULT(T) res; \
    memcpy(&res.ok, &ok, sizeof(T)); \
    res.err = 0; \
    return res; \
  } \
  \
  RESULT(T) ERR(T)(const i32 err){ \
    RESULT(T) res; \
    memset(&res.ok, (i32)'\0', sizeof(T)); \
    res.err = err; \
    return res; \
  } \
  \
  bool IS_ERR(T)(const RESULT(T) op){ \
    T ok; \
    size_t tsize = sizeof(T); \
    memset(&ok, (i32)'\0', tsize); \
    if(op.err == 0 && memcmp(&ok, &op.ok, tsize) == 0){ \
      return true; \
    } \
    return false; \
  } \
  \
  bool IS_OK(T)(const RESULT(T) op){ \
    return !IS_ERR(T)(op); \
  }

#define RETURNABLE_TRAIT_H_(T) \
  OPTION_H_(T) \
  RESULT_H_(T)

#define RETURNABLE_TRAIT_C_(T) \
  OPTION_C_(T) \
  RESULT_C_(T)

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

#define CMPR( T ) T##_cmpr  // Shorthand for calling the comparable function
#define EQ( T ) T##_eq      // Shorthand for calling the equals function

#define COMPARABLE_TRAIT_H_(T) \
  i32 CMPR( T )(const T* self, const T* other); \
  bool EQ( T )(const T* self, const T* other);

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

#define DEREF( TYPE , POINTER ) *( (TYPE*)POINTER )
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

    approx(T,
      new_string_from("hello world!"),
      new_string_from("hello WORLD!"), 50%)
      -> return true because the strings share 50% of the same elements
*/
#define APPROX( T ) T##_approx

#endif /* _LANG_H_ */
