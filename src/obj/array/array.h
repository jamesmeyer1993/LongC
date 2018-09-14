#include "types.h"
#include "object.h"
#include "array.h"

#define ARRAY_DEFSIZE 32

struct Array_ {
  Object* super;

  Object** data;
  type ofType;

  int size;
  int lastIndex;
};

typedef struct Array_ Array;

Array * initArray(type T, int size); /* constructor */
void arrayDestroy(Array * array);  /* destructor */

/* getters */
int arrayLength(Array * array);
int arrayLocate(Array * array, Object * element);  /* returns the element at a given index */
int arrayContains(Array * array, Object * element);  /* returns number of occurances of 'element' */

/* setters */
void arrayAddtoFront(Array * array, Object * element);
void arrayAddtoRear(Array * array, Object * element);
void arrayAddAt(Array * array, Object * element, int index);

void arrayClear(Array * array);
void arrayRemove(void * element);
void arrayRemoveAt(int index);
