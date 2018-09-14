#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "byte.h"

// constructor
struct ByteArray newByteArray(int size){
  struct ByteArray a;

  assert(size <= BYTE_ARRAY_LIMIT);

  a.data = malloc(size);
  a.size = size;
  // null terminating character makes the data conform to regular string functions
  a.data[size-1] = '\0';
  a.len = strlen(a.data);

  return a;
}

// de-allocate memory
void bytearrayDestroy(struct ByteArray *src)
{
  assert(src->data != NULL);
  free(src->data);
}

// reset
void bytearrayClear(struct ByteArray *src)
{
  for(int i = 0; i < src->len-1; i++)
    src->data[i] = 0;
  src->data[src->len-1] = '\0'; // padding
}

int bytearrayCompareTo(struct ByteArray *a, struct ByteArray *b)
// compares a to b. If a > b return 1. If a == b return 0; If a < b return -1;
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

bool bytearrayEquals(struct ByteArray *a, struct ByteArray *b)
{
  if(bytearrayCompareTo(a, b) == 0)
    return true;
  return false;
}

int bytearrayLocateBetween(struct ByteArray *src, byte target, int start, int end)
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
int bytearrayLocate(struct ByteArray *src, byte target)
{
  bytearrayLocateBetween(src, target, 0, src->len);
}

int bytearrayLocateSeq(struct ByteArray *src, struct ByteArray *target,
  int start, int end, int iterateby)
// Within a byte array, locates a sequence of bytes.
// An iterator is specified: "iterateby". This iterator allows for totally
// dynamic traversal of a bytearray because "iterateby" can be equal to the
// sizeof any data type or structure specified. These allows for universal
// comparison operations based on the actual byte values of any structure that
// can be transposed to a bytearray (aka. all of them).
{
  assert(target->len < src->len);
  assert(start < end && end <= src->len);
  assert(iterateby > 0);

  struct ByteArray scanner = newByteArray(target->len);

  bool found = false;
  int read = start;
  while( (read+scanner.len <= end) && (found == false) )
  {
    bytearrayCopyto(src, &scanner, read, read+scanner.len);

    if(bytearrayEquals(&scanner, target))
      found = true;
    else
      read = read + iterateby;
  }
  bytearrayDestroy(&scanner); // de-allocate scanner
  if(found == false)
    return -1; // TODO: define return values
  return read;
}

// returns the occurances of a specified byte sequence
int bytearrayOccurancesofSeq(struct ByteArray *src, struct ByteArray *target,
  int start, int end, int iterateby)
{
  assert(target->len < src->len);
  assert(start < end && end <= src->len);
  assert(iterateby > 0);

  int occurances = 0;
  int status = 0;
  while(status != -1){
    if(status == 0)
      status = bytearrayLocateSeq(src, target, status, end, iterateby);
    else
      status = bytearrayLocateSeq(src, target, status+iterateby, end, iterateby);

    if(status != -1)
      occurances++;
  }
  return occurances;
}

// bytearrayClone(...):
// produces an exact copy of the input ByteArray
struct ByteArray bytearrayClone(struct ByteArray *src)
{
  if(src->len > BYTE_ARRAY_LIMIT) // TODO: improve error handling
    exit(EXIT_FAILURE);
  struct ByteArray clone;
  clone.data = malloc(src->len);
  clone.len = src->len;
  for(int i = 0; i < clone.len; i++)
    clone.data[i] = src->data[i];
  return clone;
}

// bytearrayCopyandOmit(...):
// produces a copy of the source bytearray while omitting particular byte sequences
struct ByteArray bytearrayCopyandOmit(struct ByteArray *src,
  struct ByteArray *omit, int omitlen,
  int start, int end, int iterateby)
{
  assert(omitlen > 0);
  assert(start >= 0 && end > 0);
  assert(start < src->len && end <= src->len);
  int range = end - start;
  assert(iterateby > 0 && iterateby <= range );

  /*DEBUG*/printf("start = %d\n", start);
  /*DEBUG*/printf("end = %d\n", end);
  /*DEBUG*/printf("range = %d\n", range);

  // first, count the occurances of each sequence to omit, so
  // we can allocate the right amount of memory for the copy
  int occurances = 0; // bytes to not be allocated
  for(int i = 0; i < omitlen; i++)
    occurances=occurances+bytearrayOccurancesofSeq(src, &omit[i], start, end, iterateby);

  /*DEBUG*/printf("occrances = %d\n", occurances);

  // make an array of locations to skip
  bool* check = malloc(sizeof(bool)*(range));
  for(int i = 0; i < range; i++)
    check[i] = true;

  for(int i = 0; i < omitlen; i++)
  {
    int status = start;
    while(status != -1)
    {// locate the target
      if(status == 0)
        status = bytearrayLocateSeq(src, &omit[i], status, end, iterateby);
      else
        status = bytearrayLocateSeq(src, &omit[i], status+iterateby, end, iterateby);
      // record its range and postion
      if(status != -1){
        /*DEBUG*/printf("status = %d\n", status);
        for(int k = status; k < status+omit[i].len; k++)
          check[k] = false;
      }
    }
  }
  /*DEBUG*/
  for(int i = 0; i < range; i++)
    printf("%d", (int)check[i]);
  printf("\n");
  /*END DEBUG*/

  // instantiate the return array
  struct ByteArray sanitized = newByteArray(range-occurances);
  for(int i = start; i < end; i++){
    if(check[i-start] == true)
      sanitized.data[i-start] = src->data[i];
  }

  free(check);
  return sanitized;
}

void bytearrayCopyto(struct ByteArray *src, struct ByteArray *dest,
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

void bytearrayResize(struct ByteArray *src, int size)
{
  assert(src->len < size && size < BYTE_ARRAY_LIMIT);
  src->data = realloc(src->data, size);
  for(int i = src->len; i < size-1; i++)
    src->data[i] = 0;
  src->data[size-1] = '\0';
  src->len = size;
}

void bytearrayPrintIntsof(struct ByteArray *src)
{
  printf("\n{");
  for(int i = 0; i < src->len; i++)
    printf("%d,", (int)src->data[i]);
  printf("}\n");
}

void bytearrayPrintCharsof(struct ByteArray *src)
{
  printf("\n{");
  for(int i = 0; i < src->len; i++)
    printf("%c,", (char)src->data[i]);
  printf("}\n");
}
