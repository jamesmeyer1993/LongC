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

#define STRING_TRAIT_H_( T ) \
	String* TO_STRING( T )(T* self); \
	String* STRINGIFY( T )(T* self, T* other ); \
	String* SUBSTR( T )(const T* self, const u32 begin, const u32 end); \
	void CONCAT( T )(T* self, T* other);

#define STRING_IMPL_H_( T ) \
	String* (*to_string)(T*); \
	String* (*stringify)(T*, T*); \
	String* (*substr)(const T*, const u32, const u32); \
	void (*concat)(T*, T*);

#define STRING_IMPL_C_( T , SELF ) \
	SELF->to_string = &TO_STRING(T); \
	SELF->stringify = &STRINGIFY(T); \
	SELF->substr = &SUBSTR(T); \
	SELF->concat = &CONCAT(T);

LONGC_TRAIT_H_(String)

COLLECTION_TRAIT_H_(String, String)

STRING_TRAIT_H_(String)

#define SHIFT(T) T##_shift

// TODO: include SHIFT from array.h
void SHIFT(String)(String* self, i32 amount);

typedef struct impl_string {
	LONGC_IMPL_H_(String)
	COLLECTION_IMPL_H_(String,String)
	STRING_IMPL_H_(String)
} ImplString;

#endif /* STRING_H_ */
