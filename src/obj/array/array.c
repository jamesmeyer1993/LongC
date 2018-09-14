#include "types.h"
#include "object.h"
#include "array.h"

/* Variables of Array Type
struct Array_ {
  Object* super;
  type ofType;
  Object** data;
  int length;
};
*/

Array * initArray(type T, int size){
  Array array* = (Array*)malloc(sizeof(Array));
  array->super = initObject(T_ARRAY, array); /* inheritance */
  array->ofType = T;  // type of object this array ought to exclusively contain

  // TODO: add upward limit - ie. array cannot be greater than x size
  if(size < 1)
    array->size = ARRAY_DEFSIZE;
  else
    array->size = size;

  array->data = (Object**)malloc(array->size * sizeof(Object*));
  array->lastIndex = 0;
}

void arrayDestroy(Array * array){
  objectDestroy(array->super);
  free(array->data);
  free(array);
}

/* getters */
int arrayLength(Array * array){
  return array->lastIndex;
}

char arrayLocate(Array * array, Object * element){
  /* returns the element at a given index */
  if(element == NULL){
    printerr("NULL pointer exception.");
    exit(-1);
  }
  else if(element->T != array->ofType){
    printerr("Incompatable type exception.");
    exit(-1);
  }

  for(int i = 0; i < array->lastIndex; i++){
    
  }

}

int arrayContains(Array * array, Object * element){
  /* returns number of occurances of 'element' */
}

/* setters */
void arrayAddtoFront(Array * array, Object * element);
void arrayAddtoRear(Array * array, Object * element);
void arrayAddAt(Array * array, Object * element, int index);

void arrayClear(Array * array);
void arrayRemove(void * element);
void arrayRemoveAt(int index);
