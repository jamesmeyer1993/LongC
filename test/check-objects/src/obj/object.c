#include <stdlib.h>
/* Local imports */
#include "object.h"

/*
struct Object_ {
  byte serial[OBJECT_INIT_SIZE]
};
*/

struct Object initObject(type t, int size){
  struct Object newobj;
  newobj.serial[0] = t;
  if(size > OBJECT_INIT_SIZE){
    newobj.serial = malloc(sizeof(byte) * size);
    for(int i = 1; i < size/sizeof(byte); i++)
      newobj.serial[i] = 0;
    newobj.size = size;
  }
  else{
    newobj.size = OBJECT_INIT_SIZE;
  }
}

//struct Object objectClone(struct Object *obj);

//int objectEquals(struct Object a, struct Object b);

//int objectCompare(struct Objecct a, struct Object b);

//void objectDestroy(struct Object *obj);


//Object * initObject(type t, void * gen){
  /* define an instance of the stuct */
  //Object *obj = ( Object* ) malloc(sizeof(Object));
  /* allocate memory based on the size of the data type */
  //obj->T = t;
  //obj->generic = gen; /* TODO: I think this line is an issue. If I clone this, will two objects point to the same data? */
//}

//Object * objectClone(Object * obj){
  //Object *clone = initObject(obj->T, obj->generic);
  //Object *clone = ( Object* ) malloc(sizeof(Object));
  /* allocate memory based on the size of the data type */
  //clone->T = obj->T;
  //clone->generic = ( void * ) malloc(sizeof(obj));
//}

//int objectEquals(Object * obj_a, Object * obj_b){
  //if(obj_a->T == obj_b->T && obj_a->generic == obj_b->generic)
    //return OBJECT_COMPARE_EQUAL;
  //return 0;
//}

//int objectCompare(Object * obj_a, Object * obj_b){

  /* the objects share the same pointer */
  //if(obj_a->T == obj_b->T && obj_a->generic == obj_b->generic)
    //return OBJECT_COMPARE_EQUAL;
  /* the objects only share the same type */
  //if(obj_a->T == obj_b->T)
    //return OBJECT_COMPARE_EQUAL_TYPE;

  //return 0;
//}

//void objectDestroy(Object * obj){
  //free(obj);
//}
