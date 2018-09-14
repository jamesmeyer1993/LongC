#include <stdio.h>
#include <ctype.h>

/* local imports */
#include "obj/types.h"
#include "obj/object.h"

void test_obj_init(){
  struct Object obj = initObject(T_INT, 4);
  printf("obj.type = %d\n", obj.serial[0]);
}

int main(int argc, char **argv){
  test_obj_init();
}
