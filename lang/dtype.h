#ifndef _DTYPE_H_
#define _DYTPE_H_

#include "stdbool.h"
#include "primitives.h"

#define typed ui32_ui16    // Types are a tuple. a is the typeID and b is its size;

const typed I8   {0,1};
const typed IU8  {1,1};
const typed I16  {2,2};
const typed IU16 {3,2};
const typed I32  {4,4};
const typed UI32 {5,4};
const typed F32  {6,4};
const typed I64  {7,8};
const typed UI64 {8,8};
const typed F64  {9,8};

struct group {
  typed** dynamictypes;   // pointers must be pointers constant typed
  void* traits;           //  undefined at this point
};

struct trait {
  struct group* ofgroup;
};

void init_primitives(struct group* g){
  struct trait isprimitive{g};
}

#endif
