/*
byetesof
 - a sub-function of object, big enough to where it needs its own file
 - accepts obj pointer
 - returns seq pointer
*/
#include "../byte/byte.h"
#include "obj.h"

struct ByteArray* bytesof(struct obj* src)
{
  assert(src != NULL);

  switch(src->T)
  {
      case 0: // NULL
      case 1: return obj_bytesof(src);
      default:
        break;
  }
}
