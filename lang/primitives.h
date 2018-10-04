#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

// Additional, clearly define types provided by LongC
// Regular primitives - types
#define i8 char
#define u8 unsigned char
#define i16 short
#define u16 unsigned short
#define i32 int
#define u32 unsigned int
#define f32 float
#define i64 long
#define u64 unsigned long
#define f64 double

// tuples of two types
#define DEF_TUPLE_OF( T1 , T2 ); struct \
T1 ## _ ## T2 { \
  T1 a; \
  T2 b; \
}
// this is where all the tuples are generated
// we don't really want to write all those structures
DEF_TUPLE_OF( i8 , i8 );              // i8_i8
DEF_TUPLE_OF( i8 , u8 );   // i8_u8
DEF_TUPLE_OF( i8 , i16 );   // i8_i16
DEF_TUPLE_OF( i8 , u16 );  // ...
DEF_TUPLE_OF( i8 , i32 );
DEF_TUPLE_OF( i8 , u32 );
DEF_TUPLE_OF( i8 , i64 );
DEF_TUPLE_OF( i8 , u64 );
DEF_TUPLE_OF( i8 , f32 );
DEF_TUPLE_OF( i8 , f64 );
DEF_TUPLE_OF( u8 , u8 );
DEF_TUPLE_OF( u8 , i8 );
DEF_TUPLE_OF( u8 , i16 );
DEF_TUPLE_OF( u8 , u16 );
DEF_TUPLE_OF( u8 , i32 );
DEF_TUPLE_OF( u8 , u32 );
DEF_TUPLE_OF( u8 , i64 );
DEF_TUPLE_OF( u8 , u64 );
DEF_TUPLE_OF( u8 , f32 );
DEF_TUPLE_OF( u8 , f64 );
DEF_TUPLE_OF( i16 , i16 );
DEF_TUPLE_OF( i16 , i8 );
DEF_TUPLE_OF( i16 , u8 );
DEF_TUPLE_OF( i16 , u16 );
DEF_TUPLE_OF( i16 , i32 );
DEF_TUPLE_OF( i16 , u32 );
DEF_TUPLE_OF( i16 , i64 );
DEF_TUPLE_OF( i16 , u64 );
DEF_TUPLE_OF( i16 , f32 );
DEF_TUPLE_OF( i16 , f64 );
DEF_TUPLE_OF( u16 , u16 );
DEF_TUPLE_OF( u16 , i8 );
DEF_TUPLE_OF( u16 , u8 );
DEF_TUPLE_OF( u16 , i16 );
DEF_TUPLE_OF( u16 , i32 );
DEF_TUPLE_OF( u16 , u32 );
DEF_TUPLE_OF( u16 , i64 );
DEF_TUPLE_OF( u16 , u64 );
DEF_TUPLE_OF( u16 , f32 );
DEF_TUPLE_OF( u16 , f64 );
DEF_TUPLE_OF( i32 , i32 );
DEF_TUPLE_OF( i32 , u8 );
DEF_TUPLE_OF( i32 , i16 );
DEF_TUPLE_OF( i32 , u16 );
DEF_TUPLE_OF( i32 , u32 );
DEF_TUPLE_OF( i32 , i64 );
DEF_TUPLE_OF( i32 , u64 );
DEF_TUPLE_OF( i32 , f32 );
DEF_TUPLE_OF( i32 , f64 );
DEF_TUPLE_OF( u32 , u32 );
DEF_TUPLE_OF( u32 , i8 );
DEF_TUPLE_OF( u32 , u8 );
DEF_TUPLE_OF( u32 , i16 );
DEF_TUPLE_OF( u32 , u16 );
DEF_TUPLE_OF( u32 , i32 );
DEF_TUPLE_OF( u32 , i64 );
DEF_TUPLE_OF( u32 , u64 );
DEF_TUPLE_OF( u32 , f32 );
DEF_TUPLE_OF( u32 , f64 );
DEF_TUPLE_OF( i64 , i64 );
DEF_TUPLE_OF( i64 , i8 );
DEF_TUPLE_OF( i64 , u8 );
DEF_TUPLE_OF( i64 , i16 );
DEF_TUPLE_OF( i64 , u16 );
DEF_TUPLE_OF( i64 , i32 );
DEF_TUPLE_OF( i64 , u32 );
DEF_TUPLE_OF( i64 , u64 );
DEF_TUPLE_OF( i64 , f32 );
DEF_TUPLE_OF( i64 , f64 );
DEF_TUPLE_OF( u64 , u64 );
DEF_TUPLE_OF( u64 , i8 );
DEF_TUPLE_OF( u64 , u8 );
DEF_TUPLE_OF( u64 , i16 );
DEF_TUPLE_OF( u64 , u16 );
DEF_TUPLE_OF( u64 , i32 );
DEF_TUPLE_OF( u64 , u32 );
DEF_TUPLE_OF( u64 , i64 );
DEF_TUPLE_OF( u64 , f32 );
DEF_TUPLE_OF( u64 , f64 );

#endif
