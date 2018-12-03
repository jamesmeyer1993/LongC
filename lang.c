#include <stdlib.h>
#include <string.h>
#include <longc/lang.h>
#include <longc/traits/trait.h>
#include <longc/traits/comparable.h>

ref* new_ref(const u32 t, const void *e){
  // init a const ref on the stack;
  const ref mref = {t,e};

  // allocate on the heap the return reference
  ref *rf = malloc(sizeof(ref));

  // memcpy in order to preserve mref
  memcpy(rf, &mref, sizeof(ref));

  return rf;
}

mut_ref* new_mut_ref(u32 t, void *e){
  // the mutable reference is tied in form to the the reference. There is never
  // a time when the following ought not be true:
  assert(sizeof(mut_ref) == sizeof(ref));

  // make a mutable ref on the heap.
  mut_ref *mref = malloc(sizeof(mut_ref));
  mref->type = t;
  mref->src = e;

  // done
  return mref;
}

/* comparable functions */
i32 u8_cmpr(const u8 *self , const u8 *other ){
  return (deref(u8, self) - deref(u8, other)) % 1;
}

u32 u8_eq(const u8 *self, const u8 *other ){
  return deref(u8, self) == deref(u8, other);
}

u32 u8_approx(const u8 *self, const u8 *other, const f64 degree ){
  assert(degree < 3 && degree >= 0);

  if(degree == 0){
    return eq(u8, self, other);
  }
  else {
    u8 n = deref(u8, self);
    u8 m = deref(u8, other);

    if( degree < 1 ){
      f64 r;
      if(n > m){
        r = (n / m) * 100;
      } else {
        r = (m / n) * 100;
      }
      return r;
    }
    else if(degree == 1){
      if( (n - m) <= 9 ){
        return 1;
      }
      return 0;
    }
    else if(degree == 2){
      if( (n - m) <= 99){
        return 1;
      }
      return 0;
    }
    else {
      return 0;
    }
  }
}

i32 i8_cmpr(const i8 *self , const i8 *other ){
  return 0;
}

u32 i8_eq(const i8 *self, const i8 *other ){
  return 0;
}

u32 i8_approx(const i8 *self, const i8 *other, const f64 degree ){
  return 0;
}

i32 u16_cmpr(const u16 *self , const u16 *other ){
  return 0;
}

u32 u16_eq(const u16 *self, const u16 *other ){
  return 0;
}

u32 u16_approx(const u16 *self, const u16 *other, const f64 degree ){
  return 0;
}

i32 i16_cmpr(const i16 *self , const i16 *other ){
  return 0;
}

u32 i16_eq(const i16 *self, const i16 *other ){
  return 0;
}

u32 i16_approx(const i16 *self, const i16 *other, const f64 degree ){
  return 0;
}

i32 u32_cmpr(const u32 *self , const u32 *other ){
  return 0;
}

u32 u32_eq(const u32 *self, const u32 *other ){
  return 0;
}

u32 u32_approx(const u32 *self, const u32 *other, const f64 degree ){
  return 0;
}

i32 i32_cmpr(const i32 *self , const i32 *other ){
  return 0;
}

u32 i32_eq(const i32 *self, const i32 *other ){
  return 0;
}

u32 i32_approx(const i32 *self, const i32 *other, const f64 degree ){
  return 0;
}

i32 f32_cmpr(const f32 *self , const f32 *other ){
  return 0;
}

u32 f32_eq(const f32 *self, const f32 *other ){
  return 0;
}

u32 f32_approx(const f32 *self, const f32 *other, const f64 degree ){
  return 0;
}

i32 i64_cmpr(const i64 *self , const i64 *other ){
  return 0;
}

u32 i64_eq(const i64 *self, const i64 *other ){
  return 0;
}

u32 i64_approx(const i64 *self, const i64 *other, const f64 degree ){
  return 0;
}

i32 f64_cmpr(const f64 *self , const f64 *other ){
  return 0;
}

u32 f64_eq(const f64 *self, const f64 *other ){
  return 0;
}

u32 f64_approx(const f64 *self, const f64 *other, const f64 degree ){
  return 0;
}

i32 ref_cmpr(const ref *self , const ref *other ){
  return 0;
}

u32 ref_eq(const ref *self, const ref *other ){
  return 0;
}

u32 ref_approx(const ref *self, const ref *other, const f64 degree ){
  return 0;
}
