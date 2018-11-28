#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <longc/lang.h>
#include "../trait.h"
#include "../comparable.h"

typedef struct obj_ {
  u64 hash_code;
  void* self;
} obj;

TRAIT( COMPARABLE , obj );

i32 obj_cmpr(obj *self, obj *other){
  assert(IMPLEMENTS(COMPARABLE,obj));

  i32 r = memcmp( self, other, sizeof(obj) );

  if( r < 0){
    return -1;
  } else if( r > 0){
    return 1;
  } else {
    return 0;
  }
}

u32 obj_eq(obj *self, obj *other){
  assert(IMPLEMENTS(COMPARABLE,obj));

  if( obj_cmpr(self, other) == 0 ){
    return 1;
  } else {
    return 0;
  }
}

i32 main(void){

  //printf("\n%d\n", IMPLEMENTS(COMPARABLE,obj));
  assert( IMPLEMENTS( COMPARABLE , obj ) );

  obj o1;
  o1.hash_code = 8874;
  o1.self = NULL;

  obj o2;
  o2.hash_code = 7782;
  o2.self = NULL;

  {
    assert( obj_cmpr(&o1, &o2) != 0 );
    assert( !obj_eq( &o1, &o2) );
  }

  {
    assert( cmpr(obj, &o1, &o2) != 0);
    assert( !eq(obj, &o1, &o2) );
  }

  printf("Trait tests pass!\n");
  return 1;
}
