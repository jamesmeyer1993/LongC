#include "bignum.h"
#include <stdlib.h>
#include <stdio.h>

struct Integer newInt(byte* b, int len){
  if(len > INTEGER_BYTE_MAX)
    exit(-1); // TODO: better error handling

  printf("DEBUG: b = %s and len = %d\n", b, len);

  struct Integer x; // Instantiate the Integer

  for(int i = INTEGER_BYTE_MAX-1; i > -1; i--){
    if(i > INTEGER_BYTE_MAX-1 - len)
      x.value[i] = 0;
    else
      x.value[i] = b[INTEGER_BYTE_MAX-1 - i];
  }

  return x;
}

struct Integer addInts(struct Integer a, struct Integer b){
  struct Integer x;
  byte carry = 0;

  // TODO: change evaluation logic

  int eval = 0;
  for(int i = 255; i > -1; i--){

    eval = a.value[i]+b.value[i]+carry;

    if(eval > 255)
      carry = eval - (255);

    x.value[i] = (byte)eval;
  }
  return x;
}

struct Integer subInts(struct Integer a, struct Integer b){

}

void printHexOf(struct Integer a){
  // Allocate memory
  //int perbyte = INTEGER_BYTE_MAX / 16;
  //char* out = malloc(sizeof(a.value) * (perbyte));

  // Convert a base256 number to base16
  //for(int i = 0; i < INTEGER_BYTE_MAX; i++){
  //  for(int j = 0; j < perbyte; j++){

  //  }
  //}
}
