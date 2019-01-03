#include "../../bin/lang.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct rectangle {
  f64 length;
  f64 width;
} Rectangle;

OPTION_H_(Rectangle)

OPTION(Rectangle) init_Rectangle(f64 l, f64 w){

  OPTION(Rectangle) opt;
  if(l < 0 || w < 0){
    opt = NONE(Rectangle)();
    return opt;
  }
  else {
    Rectangle rec;;
    rec.length = l;
    rec.width = w;
    opt = SOME(Rectangle)(rec);
    return opt;
  }
}

i32 main(void){

  OPTION(Rectangle) opt = init_Rectangle(-1 , -1);
  assert(HAS_NONE(Rectangle)(opt));

  opt = init_Rectangle(2, 2);
  assert(HAS_SOME(Rectangle)(opt));

  if(HAS_SOME(Rectangle)(opt)){
    Rectangle rec = opt.some;
    assert(rec.length == 2 && rec.width == 2);
  }

  Rectangle rec;
  opt = init_Rectangle(-1 , -3);
  if(HAS_SOME(Rectangle)(opt)){
    rec = opt.some;
  }else{
    printf("Option returned none. In file: %s, line: %d\n", __FILE__, __LINE__);
  }

  opt = init_Rectangle(5, 5);
  if(HAS_SOME(Rectangle)(opt)){
    rec = opt.some;
  }else{
    printf("Option returned none. In file: %s, line: %d\n", __FILE__, __LINE__);
  }

  assert(rec.length == 5 && rec.width == 5);

  return 0;
}
