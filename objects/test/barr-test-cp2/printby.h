#ifndef _PRINTBYH_
#define _PRINTBYH_

#include <stdio.h>

void printbyInt(const char *src, int n){
  printf("\n{");
  for(int i = 0; i < n; i++){
    if(i == n-1)
      printf("%d", (int)src[i]);
    else
      printf("%d,", (int)src[i]);
  }
  printf("}\n");
}

void printbyChar(const char *src, int n){
  printf("\n{");
  for(int i = 0; i < n; i++){
    if(i == n-1)
      printf("%c", (char)src[i]);
    else
      printf("%c,", (char)src[i]);
  }
  printf("}\n");
}

#endif
