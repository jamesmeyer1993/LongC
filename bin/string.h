#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include "lang.h"

#define DEFAULT_STRING_CAPACITY 8
#define DEFAULT_STRING_LEN 0

struct string{
	i8* c;
	size_t len;
	size_t capacity;
};

typedef struct string String;

extern String* new_string();

extern String* new_string_with_capacity(const size_t capacity);

extern String* new_string_from(const char *str);

extern void init_string(String* self);

extern void init_string_from(String* self, const char* str);

extern void free_string(String *self);

//	*	*	*	MATH OPERATORS	*	*	*

extern String* string_add(const String *self, const String *other);

extern String* string_sub(const String *self, const String *other);

extern String* string_mul(const String *self, const String *other);

extern String* string_div(const String *self, const String *other);

extern String* string_mod(const String *self, const String *other);

extern String* string_xor(const String *self, const String *other);

//	*	*	*	Logic Operators	*	*	*

extern u32 string_eq(const String *self, const String *other);

extern i32 string_cmpr(const String *self, const String *other);

//	*	*	*	OPERATORS	*	*	*

extern void string_concat(String* self, String* other);

extern String* string_clone(String* self);

extern String* string_substr(const String* self, const u32 begin, const u32 end);

extern void string_shift(String* self, i32 amount);

//	*	*	*	OPERATORS	*	*	*

extern i32 string_index_of(const String* self, const String* target);

extern u32 string_ends_with(const String* self, const String* target);

extern u32 string_starts_with(const String* self, const String* target);

//	*	*	*	Display	*	*	*

extern void string_print(const String* self);

#endif /* STRING_H_ */
