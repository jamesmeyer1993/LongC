#ifndef _u8_ARRAY_H_
#define _u8_ARRAY_H_

#include "primiitves.h"

#define U8_ARRAY_DEF_CAPACITY

struct u8_array {
  u8* at;
  u32 length;
  u32 capacity;
};

void init_u8_array(struct u8_array *self);
void init_u8_array1(struct u8_array *self, u32 cap);
void init_u8_array2(struct u8_array *self, u8* array, u32 len, u32 cap);

struct u8_array* new_u8_array();
struct u8_array* new_u8_array1(u32 cap);
struct u8_array* new_u8_array2(u8* array, u32 length, u32 cap);

void u8_array_resize(struct u8_array *self);
void u8_array_resizeby(struct u8_array *self, u32 rate);
void u8_array_resizeto(struct u8_array *self, u32 cap);

// u8_array_clear
//  sets the array to zero
void u8_array_clear(struct u8_array *self);

// u8_array_trim
//  sets the capacity equal to the length
void u8_array_trim(struct u8_array *self);

#endif
