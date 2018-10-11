#include "longc/lang/primitives.h"
#include "longc/lang/reference.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/* mod_const
  This function is a test do see to what extent a constant can be modified.
*/
void mod_const(const u32 *ptr){
  u32 mutable = *ptr;
  mutable = mutable << 1;
  // this ignores the warning that we are discarding the const keyword
  #pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
  memcpy(ptr, &mutable, sizeof(u32));
}

u32 main(){

  const u32 p0 = 2;
  const u32 p1 = 3;
  const u32 p2 = 5;
  const u32 p3 = 7;
  const u32 p4 = 11;

  mod_const(&p0);
  mod_const(&p1);
  mod_const(&p2);
  mod_const(&p3);
  mod_const(&p4);

  printf("%d\n", p0);
  printf("%d\n", p1);
  printf("%d\n", p2);
  printf("%d\n", p3);
  printf("%d\n", p4);
}
