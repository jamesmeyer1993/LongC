#ifndef _CONSTRUCTABLE_FROM_H_
#define _CONSTRUCTABLE_FROM_H_

#define implements_construcable_from( T ) T ## _implements_constructable_from()

#define new_from( T1 , T2 , src ) T ## _new_from( const T2* (src) )

#define new_with_capacity( T , cap ) T ## _new_with_capacity( (cap) )

#define init_from( T1 , T2 , src ) T1 ## _init_from( const T2* (src) )

#define init_with_capacity( T , cap ) T ## _init_with_capacity( (cap) )

#define CONSTRUCTABLE_FROM_TRAIT( T1 , T2 ) \
  \
  u32 T1 ## _implements_constructable_from()
  \
  T1* T1 ## _new_from( const T2* (src) ); \
  \
  T1* T1 ## _new_with_capacity( (cap) ); \
  \
  T1 T1 ## _init_from( const T2* (src) ); \
  \
  T1 T1 ## _init_with_capacity( (cap) );


#endif //_CONSTRUCTABLE_FROM_H_
