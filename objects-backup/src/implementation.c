#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "file.h"

int main(){

  char path[] = "words.list"; // file to read
  struct Elem2048 buff; // allocate a buffer
  struct File f = newFile(path, &buff); // construct a file

  // file output
  printf("File stats:\n");
  printf("\tsize = %d\n", f.size);
  printf("\tlinecount = %d\n", f.linecount);
  printf("\tbuffers = %d\n\n", f.buffers);
  for(int i = 0; i < FILE_BUFF_LEN; i++)
    printf("%c", f.buffer->elem[i]);

  exit(0);
}
