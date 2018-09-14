#ifndef STRING_H_
#define STRING_H_

#define DEFAULT_STRING_CAPACITY 8
#define DEFAULT_STRING_LEN 0

struct string{
	char* c;
	int len;
	int capacity;
	unsigned int resizable;
};

struct string* new_string();

struct string* new_string1(int capacity);

struct string* new_string2(const char* str);

void init_string(struct string* self);

void init_string1(struct string* self, const char* str);

//	*	*	*	MATH OPERATORS	*	*	*

struct string* string_add(struct string* a, struct string* b);

struct string* string_sub(struct string* a, struct string* b);

struct string* string_mul(struct string* a, struct string* b);

struct string* string_div(struct string* a, struct string* b);

struct string* string_mod(struct string* a, struct string* b);

//	*	*	*	Logic Operators	*	*	*

int string_eq(struct string* a, struct string* b);

int string_cmpr(struct string* a, struct string* b);

//	*	*	*	OPERATORS	*	*	*

void string_copy(struct string* dest, struct string* src);

void string_concat(struct string* dest, struct string* src);

void string_append(struct string* dest, struct string* src);

struct string string_clone(struct string* self);

struct string* string_substr(struct string* src, int begin, int end);


//	*	*	*	OPERATORS	*	*	*

void string_indexof(struct string* dest, struct string* src);

int string_endswith(struct string* src, struct string* target);

int string_startswith(struct string* src, struct string* target);

//	*	*	*	Display	*	*	*

int string_print(struct string* src);



#endif /* STRING_H_ */
