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

// A bridge macro for generating the full global constant that allows the
//  developer to check if a type implements comparable
#define COMPARABLE_IMPLEMENTS( T ) T ## _implements_comparable

// The actual comparable trait as a header / function prototype declaration.
//  This macro adds the comparable functions to a type
#define COMPARABLE_TRAIT( T ) \
  \
  const u32 COMPARABLE_IMPLEMENTS( T ) = 1; \
  \
  i32 T ## _cmpr( T *self , T *other ); \
  \
  u32 T ## _eq( T *self, T *other )

#endif //_COMPARABLE_H_
