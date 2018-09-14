#ifndef _PTR_H_
#define _PTR_H_

#include "primitves.h"

#define PTR_MAX_STRUC_SIZE  256^4
#define PTR_MAX_MEMBERS     256^3
#define PTR_MAX_MEMSTATES   256

struct ptr {
  void* value;
  struct {
    // all the properties of a pointer type are encoded in 32 bytes
    //  the signing byte indicates if it is instantiated on the heap or the stack
    //  the last 16 bytes indicate
    ui64 properties;
  } priv;
};

struct ptr_properties {
  ui8 onheap;
  i32 size;
  ui32 members;
};


#endif
