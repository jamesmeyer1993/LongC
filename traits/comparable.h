#ifndef _COMPARABLE_H_
#define _COMPARABLE_H_

#include <longc/lang.h>

//    *   *   * Generic Functions *   *   *

// This is the shorthand for calling the comparable function of any type that
//  implements comparable
#define cmpr( T , self , other ) T ## _cmpr( (self), (other) )

// This is the shorthand for calling the equals function for any time that
//  implements comparable
#define eq( T , self , other ) T ## _eq( (self), (other) )

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
#define approx( T , self , other , degree ) T ## _approx( (self) , (other) , (degree) )

#define implements_comparable( T ) T ## _implements_comparable()

// The actual comparable trait as a header / function prototype declaration.
//  This macro adds the comparable functions to a type
#define COMPARABLE_TRAIT( T ) \
  \
  u32 T ## _implements_comparable(); \
  \
  i32 T ## _cmpr(const T *self , const T *other ); \
  \
  u32 T ## _eq(const T *self, const T *other ); \
  \
  u32 T ## _approx(const T *self, const T *other, const u32_f64 degree );

// const u32 T ## _implements_comparable = 1;

#endif //_COMPARABLE_H_
