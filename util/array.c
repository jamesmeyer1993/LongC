
#include <stdlib.h>
#include "../lang/primitives.h"

struct ui32_array {
  ui32* at;
  ui32 len;
  ui32 capacity;
};

void init_ui32_array(struct ui32_array* src){
  src->at = malloc(sizeof(ui32) * 8);
  src->len = 0;
  src->capacity = 8;
}

void init_ui32_array1(struct ui32_array* src, ui32 c){
  src->at = malloc(sizeof(ui32) * c);
  src->len = 0;
  src->capacity = c;
}

void init_ui32_array2(struct ui32_array* src, ui32* data, ui32 l){
  src->at = data;
  src->len = l;
  src->capacity = l;
}

ui32_array* new_ui32_array(){
  struct ui32_array* array = malloc(sizeof(ui32) * 8);
  init_ui32_array(array);
  return array;
}

ui32_array* new_ui32_array1(ui32 size){
  struct ui32_array* array = malloc(sizeof(ui32) * size);
  init_ui32_array(array);
  return array;
}

ui32_array* new_ui32_array2(struct ui32_array* src, ui32 size){
  // potential danger here. If the pointer src is allocated on the stack,
  // what happens?
  if(src != NULL){
    free(src);
  }
  struct ui32_array* array = malloc(sizeof(ui32) * size);
  init_ui32_array(array, size);
  return array;
}
