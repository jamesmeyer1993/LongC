#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct ArrayList_ {
  void** array; // generic type array
  int lastIndex;
  int size;
};

typedef struct ArrayList_ ArrayList;

ArrayList * initArrayList(){
  /* define an instance of the stuct */
  ArrayList *arrayList = ( ArrayList* ) malloc(sizeof(ArrayList));

  /* allocate memory based on the size of the data type */
  arrayList->array = (void**)malloc(2 * sizeof(void*));
  arrayList->lastIndex = 0;
  arrayList->size = 2;
}

void *pub_arrayDestroy(ArrayList * arrayList){
  free(arrayList->array);
  free(arrayList->lastIndex);
  free(arrayList->size);
  free(arrayList);
}

int pub_arrayLength(){return lastIndex;}

int pub_arraySize(){return size;}

int priv_arrayResize(){
  arrayList->array = realloc(arrayList->array, ( sizeof(arrayList->array) * sizeof(void*) ) << 1 );
  arrayList->size = arrayList->size * 2;
}

ArrayList *pub_arrayAdd(ArrayList * arrayList, void * element){

  if( arrayList->lastIndex == arrayList->size - 1) priv_resize();

  arrayList->array[arrayList->lastIndex] = element;
  arrayList->lastIndex++;

  return arrayList;
}
