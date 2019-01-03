#ifndef _RETURNABLE_H_
#define _RETURNABLE_H_

#include <stdint.h>
#include <string.h>

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
    memset(&self.some, (int32_t)'\0', sizeof(T)); \
    self.none = true; \
    return self; \
  } \
  \
  bool HAS_NONE(T)(const OPTION(T) op){ \
    T none; \
    size_t tsize = sizeof(T); \
    memset(&none, (int32_t)'\0', tsize); \
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
    int32_t err; \
  } RESULT(T); \
  \
  RESULT(T) OK(T)(const T ok); \
  RESULT(T) ERR(T)(const int32_t err); \
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
  RESULT(T) ERR(T)(const int32_t err){ \
    RESULT(T) res; \
    memset(&res.ok, (int32_t)'\0', sizeof(T)); \
    res.err = err; \
    return res; \
  } \
  \
  bool IS_ERR(T)(const RESULT(T) op){ \
    T ok; \
    size_t tsize = sizeof(T); \
    memset(&ok, (int32_t)'\0', tsize); \
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

#endif /* _RETURNABLE_H_ */
