#include <longc/lang/primitives.h>
#include <longc/lang/reference.h>
#include <assert.h>

u32 main(){

  i64 a = 9001;
  i64 b = 1003;
  i64 c = -3777;

  // look at how beautiful and elegent this constructor is!
  ref r0 = {i64_t,&a};
  ref r1 = {i64_t,&b};
  ref r2 = {i64_t,&c};

  mut_ref mr0;
  mut_ref mr1;
  mut_ret mr2;

  const u8 refsize = sizeof(ref);
  assert( sizeof(mut_ref) == refsize );
  memcpy(&mr0, &r0, refsize );
  memcpy(&mr1, &r1, refsize );
  memcpy(&mr2, &r2, refsize );
  mr0.type = u8_t;
  mr1.type = u8_t;
  mr2.type = u8_t;

  u8 e = ( to_deref(u8,mr0.src) )%256;
  u8 f = ( to_deref(u8,mr1.src) )%256;
  u8 g = ( to_deref(u8,mr2.src) )%256;

  memcpy(&r0, &mr0, refsize );
  memcpy(&r1, &mr1, refsize );
  memcpy(&r2, &mr2, refsize );

  u8 h = ( to_deref(u8,r0.src) )%256;
  u8 i = ( to_deref(u8,r1.src) )%256;
  u8 j = ( to_deref(u8,r2.src) )%256;

  assert(e == h);
  assert(f == i);
  assert(g == j);

  return 0;
}
