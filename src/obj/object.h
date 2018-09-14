#include "types.h"

#define OBJECT_COMPARE_EQUAL 1  /* return value for objectCmp */
#define OBJECT_COMPARE_EQUAL_TYPE 2 /* return value for objectCmp */

#define OBJECT_INIT_SIZE 1

struct Object {
  byte serial*;
  int size;
};

struct Object initObject(type t, int size);

struct Object objectClone(struct Object *obj);

int objectEquals(struct Object a, struct Object b);

int objectCompare(struct Objecct a, struct Object b);

void objectDestroy(struct Object *obj);
