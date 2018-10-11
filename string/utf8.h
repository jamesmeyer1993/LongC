#ifndef UTF8_H_
#define UTF8_H_

#define DEFAULT_utf8_CAPACITY 8
#define DEFAULT_utf8_LEN 0

struct utf8{
	u8* c;
	u32 len;
	u32 capacity;
	unsigned u32 resizable;
};

struct utf8* new_utf8_0();

struct utf8* new_utf8_1(const u32 capacity);

struct utf8* new_utf8_2(const u8* str, const u32 len);

void init_utf8_0(struct utf8* self);

void init_utf8_1(struct utf8* self, const u8* str);

//	*	*	*	MATH OPERATORS	*	*	*

struct utf8* utf8_add(const struct utf8* a, const struct utf8* b);

struct utf8* utf8_sub(const struct utf8* a, const struct utf8* b);

struct utf8* utf8_mul(const struct utf8* a, const struct utf8* b);

struct utf8* utf8_div(const struct utf8* a, const struct utf8* b);

struct utf8* utf8_mod(const struct utf8* a, const struct utf8* b);

//	*	*	*	Logic Operators	*	*	*

u32 utf8_eq(const struct utf8* a, const struct utf8* b);

i32 utf8_cmpr(const struct utf8* a, const  struct utf8* b);

//	*	*	*	OPERATORS	*	*	*

void utf8_copy(const struct utf8* dest, const struct utf8* src);

void utf8_concat(const struct utf8* dest, const struct utf8* src);

void utf8_append(const struct utf8* dest, const struct utf8* src);

struct utf8 utf8_clone(struct utf8* self);

struct utf8* utf8_substr(struct utf8* src, u32 begin, u32 end);


//	*	*	*	OPERATORS	*	*	*

void utf8_indexof(struct utf8* dest, struct utf8* src);

u32 utf8_endswith(struct utf8* src, struct utf8* target);

u32 utf8_startswith(struct utf8* src, struct utf8* target);

//	*	*	*	Display	*	*	*

u32 utf8_pru32(struct utf8* src);



#endif /* utf8_H_ */
