#include "arraylist.h"

ArrayList * initArrayList(type t, int s){
  /* define an instance of the stuct */
  ArrayList *list = ( ArrayList* ) malloc(sizeof(ArrayList));

  /* allocate memory based on the size of the data type */
  arrayList->array = (void**)malloc(2 * sizeof(void*));
  arrayList->lastIndex = 0;
  arrayList->size = 2;
}
