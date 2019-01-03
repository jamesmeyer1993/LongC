#ifndef _COMPARABLE_H_
#define _COMPARABLE_H_

#include <stdbool.h>
#include <string.h>
#include <math.h>

#define CMPR( T ) T##_cmpr  // Shorthand for calling the comparable function
#define EQ( T ) T##_eq      // Shorthand for calling the equals function

#define COMPARABLE_TRAIT_H_(T) \
  i32 CMPR( T )(const T* self, const T* other); \
  bool EQ( T )(const T* self, const T* other);

#define COMPARABLE_TRAIT_C_(T) \
  i32 CMPR(T)(const T* self, const T* other){ \
    i32 res = memcmp(self, other, sizeof(T)); \
    if(res < 0){ \
      return -1; \
    }else if(res > 0){ \
      return 1; \
    }else{ \
      return 0; \
    } \
  } \
  \
  bool EQ(T)(const T* self, const T* other){ \
    return (bool)abs(CMPR(T)(self, other)); \
  }

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

#endif /* _COMPARABLE_H_ */
