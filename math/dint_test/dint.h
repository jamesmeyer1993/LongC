
#ifndef _D_INT_H_
#define _D_INT_H_

#include <stdbool.h>

#define i8 char
#define u8 unsigned char
#define i32 int
#define u32 unsigned int

struct dint {
  u8* at;
  u32 length;
  u32 capacity;
};

// initializers
struct dint init_dint();

bool dint_equals(struct dint *self, struct dint *other);

i32 dint_compare(struct dint *self, struct dint *other);

void dint_set(struct dint *self, u8 *dgst, u32 dgst_len);

void dint_print_ints(struct dint *self);

#endif
