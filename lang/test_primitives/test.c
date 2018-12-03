#include <assert.h>
#include "longc/lang.h"

int main(){

  // test the instantiation of all the primitve data types
  i8 a = 'A';
  u8 b = 'B';
  i16 c = (i16)(a * b);
  u16 d = 0 - c;
  i32 e = d << 1;
  u32 f = e >> 1;
  f32 g = e / f;
  i64 h = f << 2;
  u64 i = 0 - f;
  f64 j = ( a / b ) * 3.14;

  // test the primitve data type sizes
  assert(sizeof(i8) == sizeof(char));
  assert(sizeof(u8) == sizeof(unsigned char));
  assert(sizeof(i16) == sizeof(short));
  assert(sizeof(u16) == sizeof(unsigned short));
  assert(sizeof(i32) == sizeof(int));
  assert(sizeof(u32) == sizeof(unsigned int));
  assert(sizeof(f32) == sizeof(float));
  assert(sizeof(i64) == sizeof(long));
  assert(sizeof(u64) == sizeof(unsigned long));
  assert(sizeof(f64) == sizeof(double));

  // test the tuples
  struct i8_i8 t1 = {'a','b'};  // a or b
  struct u8_u16 t2 = {'c',257}; // c or 257

  // some overflow tests
  struct i16_u16 t3 = {300 << 10, 300 << 10};
  assert( t3.a != t3.b );

  // some tuple math -> congruence relations
  struct u32_u8 t4 = { 9001 , t4.a % 256 };
  struct u32_u32 t5 = { t4.a / 256 , t5.a * 256 };
  assert(t4.a == (t5.b + t4.b) );
}
