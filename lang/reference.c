#include <stdlib.h>
#include <string.h>
#include "longc/lang/primitives.h"
#include "reference.h"

ref* new_ref(const u32 t, const void *e){
  const ref mref = {t,e};           // mref - mutable reference
  ref *rf = malloc(sizeof(ref));    // allocate a pointer for the return
  memcpy(rf, &mref, sizeof(ref));   // memcpy in order to init a malloc'd reference
  return rf;
}
