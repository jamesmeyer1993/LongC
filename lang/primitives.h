
#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

// Additional, clearly define types provided by LongC
// Regular primitives - types
typedef i8 char;
typedef ui8 unsinged char;
typedef i16 short;
typedef ui16 unsigned short;
typedef i32 int;
typedef ui32 unsigned int;
typedef f32 float;
typedef i64 long;
typedef ui64 unsigned long;
typedef f64 float;

// Tuples
// tuples of the same type
#define DEF_TUPLE_OF( T ) typedef struct{\
  T a;\
  T b;\
} T ## _ ## T;
// tuples of two types
#define DEF_TUPLE_OF_BOTH( T1 , T2 ) typedef struct{\
  T1 a;\
  T2 b;\
} T1 ## _ ## T2;
// this is where all the tuples are generated
// we don't really want to write all those structures
DEF_TUPLE_OF( i8 )              // i8_i8
DEF_TUPLE_OF_BOTH( i8 , ui8 )   // i8_ui8
DEF_TUPLE_OF_BOTH( i8 , i16 )   // i8_i16
DEF_TUPLE_OF_BOTH( i8 , ui16 )  // ...
DEF_TUPLE_OF_BOTH( i8 , i32 )
DEF_TUPLE_OF_BOTH( i8 , ui32 )
DEF_TUPLE_OF_BOTH( i8 , i64 )
DEF_TUPLE_OF_BOTH( i8 , ui64 )
DEF_TUPLE_OF_BOTH( i8 , f32 )
DEF_TUPLE_OF_BOTH( i8 , f64 )
DEF_TUPLE_OF( ui8 )
DEF_TUPLE_OF_BOTH( ui8 , i8 )
DEF_TUPLE_OF_BOTH( ui8 , i16 )
DEF_TUPLE_OF_BOTH( ui8 , ui16 )
DEF_TUPLE_OF_BOTH( ui8 , i32 )
DEF_TUPLE_OF_BOTH( ui8 , ui32 )
DEF_TUPLE_OF_BOTH( ui8 , i64 )
DEF_TUPLE_OF_BOTH( ui8 , ui64 )
DEF_TUPLE_OF_BOTH( ui8 , f32 )
DEF_TUPLE_OF_BOTH( ui8 , f64 )
DEF_TUPLE_OF( i16 )
DEF_TUPLE_OF_BOTH( i16 , i8 )
DEF_TUPLE_OF_BOTH( i16 , ui8 )
DEF_TUPLE_OF_BOTH( i16 , ui16 )
DEF_TUPLE_OF_BOTH( i16 , i32 )
DEF_TUPLE_OF_BOTH( i16 , ui32 )
DEF_TUPLE_OF_BOTH( i16 , i64 )
DEF_TUPLE_OF_BOTH( i16 , ui64 )
DEF_TUPLE_OF_BOTH( i16 , f32 )
DEF_TUPLE_OF_BOTH( i16 , f64 )
DEF_TUPLE_OF( ui16 )
DEF_TUPLE_OF_BOTH( ui16 , i8 )
DEF_TUPLE_OF_BOTH( ui16 , ui8 )
DEF_TUPLE_OF_BOTH( ui16 , i16 )
DEF_TUPLE_OF_BOTH( ui16 , i32 )
DEF_TUPLE_OF_BOTH( ui16 , ui32 )
DEF_TUPLE_OF_BOTH( ui16 , i64 )
DEF_TUPLE_OF_BOTH( ui16 , ui64 )
DEF_TUPLE_OF_BOTH( ui16 , f32 )
DEF_TUPLE_OF_BOTH( ui16 , f64 )
DEF_TUPLE_OF( i32 )
DEF_TUPLE_OF_BOTH( i32 , ui8 )
DEF_TUPLE_OF_BOTH( i32 , i16 )
DEF_TUPLE_OF_BOTH( i32 , ui16 )
DEF_TUPLE_OF_BOTH( i32 , ui32 )
DEF_TUPLE_OF_BOTH( i32 , i64 )
DEF_TUPLE_OF_BOTH( i32 , ui64 )
DEF_TUPLE_OF_BOTH( i32 , f32 )
DEF_TUPLE_OF_BOTH( i32 , f64 )
DEF_TUPLE_OF( ui32 )
DEF_TUPLE_OF_BOTH( ui32 , i8 )
DEF_TUPLE_OF_BOTH( ui32 , ui8 )
DEF_TUPLE_OF_BOTH( ui32 , i16 )
DEF_TUPLE_OF_BOTH( ui32 , ui16 )
DEF_TUPLE_OF_BOTH( ui32 , i32 )
DEF_TUPLE_OF_BOTH( ui32 , i64 )
DEF_TUPLE_OF_BOTH( ui32 , ui64 )
DEF_TUPLE_OF_BOTH( ui32 , f32 )
DEF_TUPLE_OF_BOTH( ui32 , f64 )
DEF_TUPLE_OF( i64 )
DEF_TUPLE_OF_BOTH( i64 , i8 )
DEF_TUPLE_OF_BOTH( i64 , ui8 )
DEF_TUPLE_OF_BOTH( i64 , i16 )
DEF_TUPLE_OF_BOTH( i64 , ui16 )
DEF_TUPLE_OF_BOTH( i64 , i32 )
DEF_TUPLE_OF_BOTH( i64 , ui32 )
DEF_TUPLE_OF_BOTH( i64 , ui64 )
DEF_TUPLE_OF_BOTH( i64 , f32 )
DEF_TUPLE_OF_BOTH( i64 , f64 )
DEF_TUPLE_OF( ui64 )
DEF_TUPLE_OF_BOTH( ui64 , i8 )
DEF_TUPLE_OF_BOTH( ui64 , ui8 )
DEF_TUPLE_OF_BOTH( ui64 , i16 )
DEF_TUPLE_OF_BOTH( ui64 , ui16 )
DEF_TUPLE_OF_BOTH( ui64 , i32 )
DEF_TUPLE_OF_BOTH( ui64 , ui32 )
DEF_TUPLE_OF_BOTH( ui64 , i64 )
DEF_TUPLE_OF_BOTH( ui64 , f32 )
DEF_TUPLE_OF_BOTH( ui64 , f64 )

#endif
