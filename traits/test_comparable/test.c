#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <longc/lang.h>
#include <longc/traits/trait.h>
#include <longc/traits/comparable.h>

typedef struct obj_ {
  u64 hash_code;
  void* self;
} obj;

obj init_obj(u64 code, void* ptr){
  obj self;
  self.hash_code = code;
  self.self = ptr;
  return self;
}

TRAIT( COMPARABLE , obj )

i32 obj_cmpr(const obj *self, const obj *other){
  //assert(IMPLEMENTS(COMPARABLE,obj));

  i32 r = memcmp( self, other, sizeof(obj) );

  if( r < 0){
    return -1;
  } else if( r > 0){
    return 1;
  } else {
    return 0;
  }
}

u32 obj_eq(const obj *self, const obj *other){
  //assert(IMPLEMENTS(COMPARABLE,obj));

  if( obj_cmpr(self, other) == 0 ){
    return 1;
  } else {
    return 0;
  }
}

i32 main(void){

  //printf("\n%d\n", IMPLEMENTS(COMPARABLE,obj));
  //assert( IMPLEMENTS( COMPARABLE , obj ) );

  obj o1 = init_obj(324, NULL);
  obj o2 = init_obj(7794324, NULL);
  obj o3 = init_obj(324, NULL);

  {
    assert( obj_cmpr(&o1, &o2) != 0 );
    assert( !obj_eq( &o1, &o2) );
  }

  {
    assert( cmpr(obj, &o1, &o2) != 0);
    assert( !eq(obj, &o1, &o2) );
  }

  {
    assert( cmpr(obj, &o1, &o3) == 0 );
    assert( eq(obj, &o1, &o3) == 1);
  }

  {
    //assert( IMPLEMENTS( COMPARABLE , u8) );
    u8 x = 1;
    u8 y = 2;
    printf("%d\n", cmpr(u8, &x, &y));
  }

  printf("Trait tests pass!\n");
  return 1;
}
