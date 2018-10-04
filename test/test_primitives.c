#include "/usr/include/longc/lang/primitives.h"
#include <stdlib>

int main(){

  // tests for basic primitives
  assert(sizeof(i8) == sizeof(char));
  assert(sizeof(u8) == sizeof(unsigned char));
  assert(sizeof(i16) == sizeof(short));
  assert(sizeof(u16) == sizeof(unsigned short));
  assert(sizeof(i32) == sizeof(int));
  assert(sizeof(u32) == sizeof(unsigned int));
  assert(sizeof(i64) == sizeof(long));
  assert(sizeof(u64) == sizeof(unsigned long));

  // TODO: test for all tuples. Need some kind of
  //  preprocessor this.

  // exit success
  return 0;
}
