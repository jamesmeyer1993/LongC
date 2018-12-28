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

LONGC_TRAIT_H_(String)
// String* NEW(String)();
// String INIT(String)();
// String* CLONE(String)(const String* self);
// void HEAP_FREE(String)(String* self);
// void STACK_FREE(String)(String* self);
// i32 CMPR(String)(const String* self, const String* other);
// bool EQ(String)(const String* self, const String* other);

STRING_TRAIT_H_(String)
// String* TO_STRING(String)(String* self);
// String* STRINGIFY(String)(const String* self);
// String* SUBSTR(String)(const String* self, const u32 begin, const u32 end);
// void CONCAT(String)(String* self, String* other);

//#define COLLECTION_TRAIT_( T , INT_CAP , T_OWNED )
String* NEW_WITH_CAPACITY(String)(const size_t cap);
String INIT_WITH_CAPACITY(String)(const size_t cap);
//bool CONTAINS(T)(T* self, T_OWNED* item);
u32 INDEX_OF(String)(const String* self, const String* item);
bool STARTS_WITH(String)(const String* self, const String* item);
bool ENDS_WITH(String)(const String* self, const String* item);

#define SHIFT(T) T##_shift

// TODO: include SHIFT from array.h
void SHIFT(String)(String* self, i32 amount);

#endif /* STRING_H_ */
