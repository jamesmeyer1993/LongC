#include "longc/lang/primitives.h"
#include "longc/lang/reference.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define VALID_EXIT 0

u32 array_test_256();
u32 array_test_256_subtest0(ref rlist, u32 *positive_ints);
u32 array_test_256_subtest1(ref rlist);

int main(){

  u8 c1 = 'a';
  u8 c2 = 'b';
  ref rc1 = {u8_t, &c1};
  ref rc2 = {u8_t, &c2};

  // test types
  assert(rc1.type == rc2.type);

  // test mutability
  c2 = 'a';
  u8 c3 = *( (u8*)rc1.elem);
  u8 c4 = *( (u8*)rc2.elem);
  assert( c3 == c4 );

  // test behavior on heap
  ref *rc3 = new_ref(u8_t, &c3);
  ref *rc4 = new_ref(u8_t, &c4);

  c1 = 'a';
  c2 = 'a';
  c3 = 'b';
  c4 = 'c';
  assert( *( (u8*)rc1.elem) == *( (u8*)rc2.elem) );
  assert( *( (u8*)rc3->elem) < *( (u8*)rc4->elem) );
  assert( *( (u8*)rc3->elem) == *( (u8*)rc4->elem) - 1 );

  // test deref(...)
  assert( *( (u8*)rc1.elem) == deref( u8 , rc1.elem ) );
  assert( *( (u8*)rc2.elem) == deref( u8 , rc2.elem ) );
  assert( *( (u8*)rc3->elem) == deref( u8 , rc3->elem ) );
  assert( *( (u8*)rc4->elem) == deref( u8 , rc4->elem ) );

  u8 c5 = deref(u8,rc1.elem);
  u8 c6 = deref(u8,rc2.elem);
  u8 c7 = deref(u8,rc3->elem);
  u8 c8 = deref(u8,rc4->elem);
  assert(c5 == c1);
  assert(c6 == c2);
  assert(c7 == c3);
  assert(c8 == c4);

  // cleanup
  free(rc3);
  free(rc4);

  // array tests
  assert(array_test_256() == VALID_EXIT);
}

u32 array_test_256(){

  u32 *positive_ints = malloc(sizeof(u32) * 256);
  for(u32 i = 0; i < 256; i++){
    positive_ints[i] = i;
    printf("%d,", positive_ints[i]);
  }

  ref rlist = {u32_t,positive_ints};
  assert(array_test_256_subtest0(rlist, positive_ints) == VALID_EXIT);
  assert(array_test_256_subtest1(rlist) == VALID_EXIT);

  free(positive_ints);
  return VALID_EXIT;
}

u32 array_test_256_subtest0(ref rlist, u32 *int_array){
  u32 *iterator = (u32*)rlist.elem;
  for(u32 i = 0; i < 256; i++){
    assert(iterator[i] == int_array[i]);
    printf("DEBUG: iterator[%d] == %d\n", i, iterator[i]);
  }
  return VALID_EXIT;
}

u32 array_test_256_subtest1(ref rlist){
  u32 *iterator = (u32*)rlist.elem;
  u32 onstack = 0;
  for(u32 i = 0; i < 256; i++){
    onstack = iterator[i];
    assert(onstack == iterator[i]);
    printf("DEBUG: onstack == %d\n", onstack);
  }
  return VALID_EXIT;
}
