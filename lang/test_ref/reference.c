#include <string.h>
#include <stdlib.h>
#include "reference.h"

#include <stdio.h>

ref* new_ref(const u8 t, const void *e){
  const ref mref = {t,e};           // mref - mutable reference
  ref *rf = malloc(sizeof(ref));    // allocate a pointer for the return
  memcpy(rf, &mref, sizeof(ref));   // memcpy in order to init a malloc'd reference
  return rf;
}
