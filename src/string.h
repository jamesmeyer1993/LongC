#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include "lang.h"

#define DEFAULT_STRING_CAPACITY 8
#define DEFAULT_STRING_LEN 0

struct string{
	char* str;
	size_t len;
	size_t cap;
};

typedef struct string String;

// Generic Functions of the String Type

// generic arg expansion
String* NEW(String)();

String* NEW_FROM(String, chars)(const char* str);

String* NEW(String)_with_capacity(size_t cap);

String INIT(String)();

String INIT_FROM(String, chars)(const char* str);

String INIT(String)_with_capacity(size_t cap);

String CLONE(String)(const String* self);

void HEAP_FREE(String)(String* self);

void STACK_FREE(String)(String* self);

// ## to_String(...)
//	@accepts the type of self, T and SELF
//	@returns a string representation of an object
#define TO_STRING( T ) T##_to_String

// stringify(...)
//	@accepts the type of self, T and SELF
//	@returns a representation of self serialized as a string
#define STRINGIFY( T ) T##_stringify

#define SUBSTR( T ) T##_substr

#define CONCAT( T ) T##_concat

#define STRING_TRAITS_H_( T ) \
	STRINGIFY( T )(T* self, T* other ); \
	SUBSTR( T )(T* self, const u32 begin, const u32 end); \
	CONCAT( T )(T* self, T* other); 

//	*	*	*	Logic Operators	*	*	*

u32 EQ(String)(String* self, String* other);
// u32 string_eq(const String *self, const String *other);

i32 CMPR(String)(String* self, String* other);
// i32 string_cmpr(const String *self, const String *other);

f64 APPROX(String)(String* self, String* other);

//	*	*	*	OPERATORS	*	*	*

void CONCAT(String)(String* self, String* other);
// void string_concat(String* self, String* other);

String* CLONE(String)(String* self);
// String* string_clone(String* self);

String* SUBSTR(String)(const String* self, const u32 begin, const u32 end);
// String* string_substr(const String* self, const u32 begin, const u32 end);

// void string_shift(String* self, i32 amount);

//	*	*	*	OPERATORS	*	*	*

// i32 string_index_of(const String* self, const String* target);
//
// u32 string_ends_with(const String* self, const String* target);
//
// u32 string_starts_with(const String* self, const String* target);

//	*	*	*	Display	*	*	*

// void string_print(const String* self);


// String* new_string();
//
// String* new_string_with_capacity(const size_t capacity);
//
// String* new_string_from(const char *str);
//
// void init_string(String* self);
//
// void init_string_from(String* self, const char* str);
//
// void free_string(String *self);

//	*	*	*	MATH OPERATORS	*	*	*

// String* string_add(const String *self, const String *other);
//
// String* string_sub(const String *self, const String *other);
//
// String* string_mul(const String *self, const String *other);
//
// String* string_div(const String *self, const String *other);
//
// String* string_mod(const String *self, const String *other);
//
// String* string_xor(const String *self, const String *other);

#endif /* STRING_H_ */
