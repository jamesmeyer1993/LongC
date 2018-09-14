#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "byte.h"
//#include "elem.h"
//#include "file.h"
//#include "word.h"
//#include "wordarray.h"

int main(){

  struct ByteArray b_array = newByteArray(1024);
  printf("b_array length = %d\n", b_array.len);
  for(int i = 0; i < b_array.len-1; i++)
    b_array.data[i] = (byte)i;

  bytearrayPrintIntsof(&b_array);

  // locate all occurances of query
  int pos = 0;
  byte query = 2;
  do
  {
    pos = bytearrayLocateBetween(&b_array, query, pos, b_array.len);
    printf("location of %d \'2\' = %d\n",query,pos);
  }
  while(pos != -1);

  bytearrayDestroy(&b_array);
/*
  char path[] = "words.list"; // file to read
  struct ByteArray = newByteArray(2024); // allocate a buffer
  struct File f = newFile(path, &buff); // construct a file

  // file output
  printf("File stats:\n");
  printf("\tsize = %d\n", f.size);
  printf("\tlinecount = %d\n", f.linecount);
  printf("\tlastnewline = %d\n", f.lastnewline);
  printf("\tbuffers = %d\n\n", f.buffers);

  struct WordArray w_array = newWordArray(buff.elem, 2048);
*/
  exit(0);
}
