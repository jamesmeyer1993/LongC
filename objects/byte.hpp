#ifndef _BYTEH_
#define _BYTEH_

#include <stdbool.h>

#define SIZEOF_BYTE 256;
typedef unsigned char byte;

/*
kb  : bytes
2   : 2048
4   : 4096
8   : 8192
16  : 16384
32  : 32768
64  : 65536
128 : 131072
*/
#define BYTE_ARRAY_LIMIT 1048

struct ByteArray{
  int size;   // size in bytes
  int len;    // size - '\0'
  byte* data; // variable array of bytes
};

// constructor
struct ByteArray newByteArray(int size);

// destructor
void bytearrayDestroy(struct ByteArray *src);

bool bytearrayEquals(struct ByteArray *a, struct ByteArray *b);

int bytearrayCompareTo(struct ByteArray *a, struct ByteArray *b);

// search
int bytearrayLocate(struct ByteArray *src, byte target);

// search
int bytearrayLocateBetween(struct ByteArray *src, byte target, int start, int end);

// bytearrayLocateSeq(...):
// Within a byte array, locates a sequence of bytes.
// An iterator is specified: "iterateby". This iterator allows for totally
// dynamic traversal of a bytearray because "iterateby" can be equal to the
// sizeof any data type or structure specified. These allows for universal
// comparison operations based on the actual byte values of any structure that
// can be transposed to a bytearray (aka. all of them).
int bytearrayLocateSeq(struct ByteArray *src, struct ByteArray *target,
  int start, int end, int iterateby);

// returns the occurances of a specified byte sequence
int bytearrayOccurancesofSeq(struct ByteArray *src, struct ByteArray *target,
  int start, int end, int iterateby);

// bytearrayClear(...):
// sets each element of the byte array to 0, excluding the terminating character
void bytearrayClear(struct ByteArray *src);

// bytearrayClone(...):
// produces an exact copy of the input ByteArray
struct ByteArray bytearrayClone(struct ByteArray *src);

// bytearrayCopyandOmit(...):
// produces a copy of the source bytearray while omitting particular byte sequences
struct ByteArray bytearrayCopyandOmit(struct ByteArray *src,
  struct ByteArray *omit, int omitlen,
  int start, int end, int iterateby);

void bytearrayCopyto(struct ByteArray *src, struct ByteArray *dest,
  int start, int end);

void bytearrayResize(struct ByteArray *src, int size);

// display
void bytearrayPrintIntsof(struct ByteArray *src);

void bytearrayPrintCharsof(struct ByteArray *src);

#endif
