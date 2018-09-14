#ifndef _FILEH_
#define _FILEH_

#include <stdio.h>
#include "elem.h"

#define FILE_BUFF_LEN 2048

struct File{
  FILE* f;
  int size;
  int linecount;
  int buffers;  // number of times required to read the file
  struct Elem2048 *buffer; // actual content read into the buffer in bytes
};

struct File newFile(const char *path, struct Elem2048 *buff){
  // open the file
  FILE* toread = fopen(path, "r");
  char input = ' ';
  // Generate the file
  struct File f;
  f.size=0;
  f.linecount=0;
  f.buffers=0;
  f.buffer = buff;
  // Fill the buffer TODO: Needs work
  do{
    input = fgetc(toread);
    f.size++;
    if(f.size < FILE_BUFF_LEN)
      f.buffer->elem[f.size]=input;
    if(input == '\n')
      f.linecount++;
  }while(input != EOF);
  // double check the buffer measurements
  f.buffers = f.size / FILE_BUFF_LEN;
  if(f.buffers * FILE_BUFF_LEN < f.size)
    f.buffers++;

  fclose(toread);
  return f;
};

#endif
