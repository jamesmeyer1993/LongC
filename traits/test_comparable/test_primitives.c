#include <assert.h>
#include <longc/lang.h>
#include <longc/traits/comparable.h>
#include <longc/lang/primitive.h>

i32 main(void){

  {
    u8 x = 1;
    u8 y = 2;

    assert( implements_comparable(u8) );
    assert( cmpr(u8, &x, &y) != 0 );
    assert( !eq(u8, &x, &y) );

    y = 1;
    assert( eq(u8, &x, &y) );
  }

  return 0;
}
