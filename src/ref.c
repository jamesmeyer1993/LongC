#include <stdlib.h>
#include <string.h>
#include <longc/lang.h>
#include <longc/traits/trait.h>
#include <longc/traits/comparable.h>

ref* new_ref(const u32 t, const void *e){
  // init a const ref on the stack;
  const ref mref = {t,e};

  // allocate on the heap the return reference
  ref *rf = malloc(sizeof(ref));

  // memcpy in order to preserve mref
  memcpy(rf, &mref, sizeof(ref));

  return rf;
}

mut_ref* new_mut_ref(u32 t, void *e){
  // the mutable reference is tied in form to the the reference. There is never
  // a time when the following ought not be true:
  assert(sizeof(mut_ref) == sizeof(ref));

  // make a mutable ref on the heap.
  mut_ref *mref = malloc(sizeof(mut_ref));
  mref->type = t;
  mref->src = e;

  // done
  return mref;
}

// i32 ref_cmpr(const ref *self , const ref *other ){
//   return 0;
// }
//
// u32 ref_eq(const ref *self, const ref *other ){
//   return 0;
// }
//
// u32 ref_approx(const ref *self, const ref *other, const f64 degree ){
//   return 0;
// }
