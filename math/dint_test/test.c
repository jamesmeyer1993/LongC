#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "dint.h"

int main(){

  i8 *str1 = "What we do in this life echoes an eternity!";
  i8 *str2 = "There is nothing to fear but fear itself.";

  struct dint digest1 = init_dint();
  struct dint digest2 = init_dint();

  dint_set(&digest1, str1, strlen(str1));
  dint_set(&digest2, str2, strlen(str2));

  dint_print_ints(&digest1);
  dint_print_ints(&digest2);

  assert(dint_equals(&digest1, &digest2) == false);
  assert(dint_compare(&digest1, &digest2) != 0);
  assert(dint_compare(&digest1, &digest2) == 1);
}
