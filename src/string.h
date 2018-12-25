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

String* new_string();

String* new_string_with_capacity(const size_t capacity);

String* new_string_from(const char *str);

void init_string(String* self);

void init_string_from(String* self, const char* str);

void free_string(String *self);

//	*	*	*	MATH OPERATORS	*	*	*

String* string_add(const String *self, const String *other);

String* string_sub(const String *self, const String *other);

String* string_mul(const String *self, const String *other);

String* string_div(const String *self, const String *other);

String* string_mod(const String *self, const String *other);

String* string_xor(const String *self, const String *other);

//	*	*	*	Logic Operators	*	*	*

u32 string_eq(const String *self, const String *other);

i32 string_cmpr(const String *self, const String *other);

//	*	*	*	OPERATORS	*	*	*

void string_concat(String* self, String* other);

String* string_clone(String* self);

String* string_substr(const String* self, const u32 begin, const u32 end);

void string_shift(String* self, i32 amount);

//	*	*	*	OPERATORS	*	*	*

i32 string_index_of(const String* self, const String* target);

u32 string_ends_with(const String* self, const String* target);

u32 string_starts_with(const String* self, const String* target);

//	*	*	*	Display	*	*	*

void string_print(const String* self);

#endif /* STRING_H_ */
