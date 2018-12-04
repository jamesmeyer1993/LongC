#ifndef _CONSTRUCTABLE_H_
#define _CONSTRUCTABLE_H_

#define implements_constructable( T ) T ## _implements_constructable

#define new( T ) T ## _new()

#define init( T ) T ## _init()

#define CONSTRUCTABLE_TRAIT( T ) \
  \
  u32 T ## _implements_constructable();
  \
  T* T ## _new(); \
  \
  T T ## _init();

#endif // _CONSTRUCTABLE_H_
