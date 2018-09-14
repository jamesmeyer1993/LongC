#ifndef _BYTEH_
#define _BYTEH_

#include <stdbool.h>

#include "../obj.h"

#ifndef T_BYTE
  #define T_BTYE 2
#endif

#ifndef T_BYTESEQ
  #define T_BYTESEQ 12
#endif

#define BYTE_ARRAY_LIMIT 1048

struct byteseq
{
  int size;         // size in bytes
  int len;          // size - '\0'
  bool resizeable;  // flag
  byte* data;       // variable array of bytes
};

// constructors
struct byteseq* newbyteseq(int size);

struct byteseq* newbyteseq1(const char* str);

struct byteseq* newbyteseq2(int size, bool resize);

struct byteseq* newbyteseq3(const char* str, bool resize);

// destructor
void byteseqDestroy(struct byteseq *src);

// similar to, but more dynamic than strcpy
// overwrites the existing values of dest->data
void byteseqSet(struct byteseq *dest, const char* src);

// similar to, but more dynamic than strcat
// adds values to dest->data up to the array limit
void byteseqAdd(struct byteseq *dest, const char* src);

struct byteseq* byteseqSub(struct byteseq *src,
  int start, int end);

bool byteseqEquals(struct byteseq *a, struct byteseq *b);

int byteseqCompareTo(struct byteseq *a, struct byteseq *b);

// search
int byteseqLocate(struct byteseq *src, byte target);

// search
int byteseqLocateBetween(struct byteseq *src, byte target, int start, int end);

// byteseqLocateSeq(...):
// Within a byte array, locates a sequence of bytes.
// An iterator is specified: "iterateby". This iterator allows for totally
// dynamic traversal of a byteseq because "iterateby" can be equal to the
// sizeof any data type or structure specified. These allows for universal
// comparison operations based on the actual byte values of any structure that
// can be transposed to a byteseq (aka. all of them).
int byteseqLocateSeq(struct byteseq *src, struct byteseq *target,
  int start, int end, int iterateby);

// returns the occurances of a specified byte sequence
int byteseqOccurancesofSeq(struct byteseq *src, struct byteseq *target,
  int start, int end, int iterateby);

// byteseqClear(...):
// sets each element of the byte array to 0, excluding the terminating character
void byteseqClear(struct byteseq *src);

// byteseqClone(...):
// produces an exact copy of the input byteseq
struct byteseq* byteseqClone(struct byteseq *src);

// byteseqCopyandOmit(...):
// produces a copy of the source byteseq while omitting particular byte sequences
struct byteseq* byteseqCopyandOmit(struct byteseq *src,
  struct byteseq *omit, int omitlen,
  int start, int end, int iterateby);

void byteseqCopyto(struct byteseq *src, struct byteseq *dest,
  int start, int end);

void byteseqResize(struct byteseq *src, int size);

struct obj* byteseq_toobj(struct byteseq *src);

#endif
