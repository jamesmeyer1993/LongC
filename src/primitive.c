#include <assert.h>
#include <math.h>
#include <string.h>
#include <longc/lang.h>
#include <longc/lang/primitive.h>
#include <longc/traits/comparable.h>

#define LOCAL_PRIMITIVE_CMPR( T , self , other ) \
  T _n_ = deref( T , self ); \
  T _m_ = deref( T , other ); \
  if( _n_ > _m_ ){ \
    return 1; \
  } else if( _n_ < _m_ ){ \
    return -1; \
  } else { \
    return 0; \
  }

/* comparable functions */
u32 u8_implements_comparable(){ return 1; }

u32 i8_implements_comparable(){ return 1; }

u32 u16_implements_comparable(){ return 1; }

u32 i16_implements_comparable(){ return 1; }

u32 u32_implements_comparable(){ return 1; }

u32 i32_implements_comparable(){ return 1; }

u32 f32_implements_comparable(){ return 1; }

u32 i64_implements_comparable(){ return 1; }

u32 f64_implements_comparable(){ return 1; }

i32 u8_cmpr(const u8 *self , const u8 *other ){
  LOCAL_PRIMITIVE_CMPR( u8 , self , other );
}

u32 u8_eq(const u8 *self, const u8 *other ){
  return deref(u8, self) == deref(u8, other);
}

u32 u8_approx(const u8 *self, const u8 *other, const u32_f64 degree ){
  return 0;
}

i32 i8_cmpr(const i8 *self , const i8 *other ){
  LOCAL_PRIMITIVE_CMPR( i8 , self , other );
}

u32 i8_eq(const i8 *self, const i8 *other ){
  return deref(i8, self) == deref(i8, other);
}

u32 i8_approx(const i8 *self, const i8 *other, const u32_f64 degree ){
  return 0;
}

i32 u16_cmpr(const u16 *self , const u16 *other ){
  LOCAL_PRIMITIVE_CMPR( u16 , self , other );
}

u32 u16_eq(const u16 *self, const u16 *other ){
  return deref(u16, self) == deref(u16, other);
}

u32 u16_approx(const u16 *self, const u16 *other, const u32_f64 degree ){
  return 0;
}

i32 i16_cmpr(const i16 *self , const i16 *other ){
  LOCAL_PRIMITIVE_CMPR( i16 , self , other );
}

u32 i16_eq(const i16 *self, const i16 *other ){
  return deref(u16, self) == deref(u16, other);
}

u32 i16_approx(const i16 *self, const i16 *other, const u32_f64 degree ){
  return 0;
}

i32 u32_cmpr(const u32 *self , const u32 *other ){
  LOCAL_PRIMITIVE_CMPR( i8 , self , other );
}

u32 u32_eq(const u32 *self, const u32 *other ){
  return deref(u32, self) == deref(u32, other);
}

u32 u32_approx(const u32 *self, const u32 *other, const u32_f64 degree ){
  return 0;
}

i32 i32_cmpr(const i32 *self , const i32 *other ){
  LOCAL_PRIMITIVE_CMPR( i32 , self , other );
}

u32 i32_eq(const i32 *self, const i32 *other ){
  return deref(i32, self) == deref(i32, other);
}

u32 i32_approx(const i32 *self, const i32 *other, const u32_f64 degree ){
  return 0;
}

i32 f32_cmpr(const f32 *self , const f32 *other ){
  LOCAL_PRIMITIVE_CMPR( f32 , self , other );
}

u32 f32_eq(const f32 *self, const f32 *other ){
  return deref(f32, self) == deref(f32, other);
}

u32 f32_approx(const f32 *self, const f32 *other, const u32_f64 degree ){
  return 0;
}

i32 i64_cmpr(const i64 *self , const i64 *other ){
  LOCAL_PRIMITIVE_CMPR( i64 , self , other );
}

u32 i64_eq(const i64 *self, const i64 *other ){
  return deref(i64, self) == deref(i64, other);
}

u32 i64_approx(const i64 *self, const i64 *other, const u32_f64 degree ){
  return 0;
}

i32 f64_cmpr(const f64 *self , const f64 *other ){
  LOCAL_PRIMITIVE_CMPR( f64 , self , other );
}

u32 f64_eq(const f64 *self, const f64 *other ){
  return deref(f64, self) == deref(f64, other);
}

u32 f64_approx(const f64 *self, const f64 *other, const u32_f64 degree ){
  return 0;
}

#ifdef LOCAL_PRIMITIVE_CMPR
  #undef LOCAL_PRIMITIVE_CMPR
#endif
