#include "longc/lang/primitives.h"
#include "reference.h"
#include <assert.h>
#include <stdlib.h>

#define TYPE_U8 1

int main(){

  u8 c1 = 'a';
  u8 c2 = 'b';
  ref rc1 = {TYPE_U8, &c1};
  ref rc2 = {TYPE_U8, &c2};

  // test types
  assert(rc1.type == rc2.type);

  // test mutability
  c2 = 'a';
  u8 c3 = *( (u8*)rc1.elem);
  u8 c4 = *( (u8*)rc2.elem);
  assert( c3 == c4 );

  // test behavior on heap
  ref *rc3 = new_ref(TYPE_U8, &c3);
  ref *rc4 = new_ref(TYPE_U8, &c4);

  c1 = 'a';
  c2 = 'a';
  c3 = 'b';
  c4 = 'c';
  assert( *( (u8*)rc1.elem) == *( (u8*)rc2.elem) );
  assert( *( (u8*)rc3->elem) < *( (u8*)rc4->elem) );
  assert( *( (u8*)rc3->elem) == *( (u8*)rc4->elem) - 1 );

  free(rc3);
  free(rc4);
}
