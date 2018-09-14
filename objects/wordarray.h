#ifndef _WORDARRAY_
#define _WORDARRAY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "byte.h"
#include "word.h"

struct WordArray {
  int len;      // number of elements
  int bytesof;  // total bytes
  struct Word *head;  // head & tail - two more ints for more secure memory management
  struct Word *data;
  struct Word *tail;
};

struct WordArray makeNullArray(){
  struct WordArray w;
  w.len=0;
  w.head = NULL;
  w.data = NULL;
  w.tail = NULL;
  w.bytesof=(sizeof(w));
  return w;
}

struct WordArray newWordArray(byte* buffer, int buflen){

  int newlines = 0;
  for(int i = 0; i < buflen; i++){
    if(buffer[i] == '\n') newlines++;
  }

  int *nlpos = malloc(newlines * sizeof(int));
  int index = 0;
  for(int i = 0; i < buflen; i++){
    if(buffer[i] = '\n'){
      nlpos[index] = i;
      index++;
    }
  }

  for(int i = 0; i < newlines; i++)
    printf("nlpos[%d]=%d\n", i, nlpos[i]);

  free(nlpos);
  return makeNullArray();
};

#endif
