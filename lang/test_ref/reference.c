#include <string.h>
#include <stdlib.h>
#include "reference.h"

ref* new_ref(const u32 t, const void *e){
  const ref mref = {t,e};
  //mut_ref mref = {t,e};
  ref *rf = malloc(sizeof(ref));
  memcpy(rf, &mref, sizeof(ref));
  return rf;
}
