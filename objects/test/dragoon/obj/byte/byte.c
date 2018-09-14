#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../obj.h"
#include "byte.h"

// constructor
struct byteseq* newbyteseq(int size)
{
  assert(size <= BYTE_ARRAY_LIMIT);

  struct byteseq* a = malloc(sizeof(struct byteseq));

  a->data = malloc(size);
  a->size = size;
  // null terminating character makes the data conform to regular string functions
  for(int i = 0; i < size; i++)
    a->data[i] = '\0';
  a->len = strlen(a->data);
  a->resizeable = false;
  return a;
}

// constructor option 1
struct byteseq* newbyteseq1(const char* str)
{
  int size = strlen(str);
  struct byteseq* a = newbyteseq(size + 1);
  byteseqSet(a, str);
  return a;
}

// constructor option 2
struct byteseq* newbyteseq2(int size, bool resize)
{
  struct byteseq* a = newbyteseq(size);
  a->resizeable = resize;
  return a;
}

// constructor option 3
struct byteseq* newbyteseq3(const char* str, bool resize)
{
  struct byteseq* a = newbyteseq1(str);
  a->resizeable = resize;
  return a;
}

// de-allocate memory
void byteseqDestroy(struct byteseq *src)
{
  assert(src != NULL && src->data != NULL);
  free(src->data);
  free(src);
}

void byteseqSet(struct byteseq *dest, const char* src)
{
  int len = strlen(src);
  assert(len <= BYTE_ARRAY_LIMIT);

  if(len > dest->size-1){
    if(dest->resizeable == true){
      byteseqResize(dest, len+1);
      strcpy(dest->data, src);
    }
    else
      strncpy(dest->data, src, dest->size-1);
  }
  else
    strcpy(dest->data, src);

  dest->len = strlen(dest->data);
}

void byteseqAdd(struct byteseq *dest, const char* src)
{
  int len = strlen(src);
  int nextlen = len + dest->len;
  assert(nextlen <= BYTE_ARRAY_LIMIT);

  if(nextlen > dest->size-1){
    if(dest->resizeable == true){
      byteseqResize(dest, nextlen+1);
      strcat(dest->data, src);
    }
    else
      strncat(dest->data, src, dest->size-1);
  }
  else
    strcat(dest->data, src);

  dest->len = strlen(dest->data);
}

struct byteseq* byteseqSub(struct byteseq *src,
  int start, int end)
// returns a substring from "start" to, but not including "end"
{
  assert(end > start);
  assert(start > -1);
  assert(end <= src->len);
  struct byteseq* sub = newbyteseq(end - start + 1);
  // get the substring
  for(int i = start; i < end; i++)
    sub->data[i-start] = src->data[i];

  sub->len = strlen(sub->data);

  return sub;
};

// reset
void byteseqClear(struct byteseq *src)
{
  for(int i = 0; i < src->len-1; i++)
    src->data[i] = 0;
  src->data[src->len-1] = '\0'; // padding
}

int byteseqCompareTo(struct byteseq *a, struct byteseq *b)
// compares a to b-> If a > b return 1-> If a == b return 0; If a < b return -1;
{
  if(a->len != b->len)
  {
    if(a->len > b->len) return 1;
    else return -1;
  }
  else
  {
    int i = 0;
    while(i < a->len && i < b->len)
    {
      if(a->data[i] != b->data[i])
      {
        if(a->data[i] > b->data[i]) return 1;
        else return -1;
      }
      i++;
    }
    return 0;
  }

}

bool byteseqEquals(struct byteseq *a, struct byteseq *b)
{
  if(byteseqCompareTo(a, b) == 0)
    return true;
  return false;
}

int byteseqLocateBetween(struct byteseq *src, byte target, int start, int end)
// iterates through a byte array, looking for a particular byte, with a starting
// position and an ending position. If the element is not found, -1 is returned.
// TODO: define default return values
{
  bool found = false;
  int index = start;
  while(found==false && index<end){
    if(src->data[index] == target)
      found = true;
    else
      index++;
  }
  if(found==false)
    return -1;
  return index;
}
// see above
int byteseqLocate(struct byteseq *src, byte target)
{
  byteseqLocateBetween(src, target, 0, src->len);
}

int byteseqLocateSeq(struct byteseq *src, struct byteseq *target,
  int start, int end, int iterateby)
// Within a byte array, locates a sequence of bytes.
// An iterator is specified: "iterateby". This iterator allows for totally
// dynamic traversal of a byteseq because "iterateby" can be equal to the
// sizeof any data type or structure specified. These allows for universal
// comparison operations based on the actual byte values of any structure that
// can be transposed to a byteseq (aka. all of them).
{
  assert(target->len < src->len);
  assert(start < end && end <= src->len);
  assert(iterateby > 0);

  struct byteseq* scanner = newbyteseq(target->len);

  bool found = false;
  int read = start;
  while( (read+scanner->len <= end) && (found == false) )
  {
    byteseqCopyto(src, scanner, read, read+scanner->len);

    if(byteseqEquals(scanner, target))
      found = true;
    else
      read = read + iterateby;
  }
  byteseqDestroy(scanner); // de-allocate scanner
  if(found == false)
    return -1; // TODO: define return values
  return read;
}

// returns the occurances of a specified byte sequence
int byteseqOccurancesofSeq(struct byteseq *src, struct byteseq *target,
  int start, int end, int iterateby)
{
  assert(target->len < src->len);
  assert(start < end && end <= src->len);
  assert(iterateby > 0);

  int occurances = 0;
  int status = 0;
  while(status != -1){
    if(status == 0)
      status = byteseqLocateSeq(src, target, status, end, iterateby);
    else
      status = byteseqLocateSeq(src, target, status+iterateby, end, iterateby);

    if(status != -1)
      occurances++;
  }
  return occurances;
}

// byteseqClone(...):
// produces an exact copy of the input byteseq
struct byteseq* byteseqClone(struct byteseq *src)
{
  if(src->len > BYTE_ARRAY_LIMIT) // TODO: improve error handling
    exit(EXIT_FAILURE);

  struct byteseq* clone = malloc(sizeof(struct byteseq));
  clone->data = malloc(src->len);
  clone->len = src->len;
  for(int i = 0; i < clone->len; i++)
    clone->data[i] = src->data[i];
  return clone;
}

// byteseqCopyandOmit(...):
// produces a copy of the source byteseq while omitting particular byte sequences
struct byteseq* byteseqCopyandOmit(struct byteseq *src,
  struct byteseq *omit, int omitlen,
  int start, int end, int iterateby)
{
  // TODO
}

void byteseqCopyto(struct byteseq *src, struct byteseq *dest,
  int start, int end)
{
  assert(start < end);
  assert( (end - start) <= dest->len && (end - start) <= src->len );
  int j = 0;
  for(int i = start; i < end; i++){
    dest->data[j] = src->data[i];
    j++;
  }
}

void byteseqResize(struct byteseq *src, int size)
{
  assert(src->len < size && size < BYTE_ARRAY_LIMIT);
  src->data = realloc(src->data, size);
  src->size = size;
  src->len = src->size - 1;
  src->data[src->len] = '\0';
}

struct obj* byteseq_toobj(struct byteseq *src)
{
  return newobj(T_BYTESEQ, src);
}
