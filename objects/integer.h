#include "elem.h"

#define INTEGER_BYTE_MAX 256

typedef unsigned char byte;

struct Integer{
  struct elem8 elem8;
};

struct Integer newInt(byte* b, int len);

struct Integer addInts(struct Integer a, struct Integer b);

struct Integer subInts(struct Integer a, struct Integer b);

void printHexOf(struct Integer a);
