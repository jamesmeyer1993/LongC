#include "../../bin/lang.h"
#include "../../bin/constructable.h"
#include "../../bin/string.h"

i32 main(void){

  {
    String* str = new(String);
    heap_free(String, str);
  }

  {
    String* str = new_from(String, chars, "Generic typed functions are nice!");
    heap_free(String, str);
  }

  {
    String* str = new_with_capacity(String, 128);
    heap_free(String, str);
  }

  {
    String str = init(String);
    stack_free(String, &str);
  }

  {
    String str = init_from(String, chars, "Sometimes the stack is best.");
    stack_free(String, &str);
  }

  {
    String str = init_with_capacity(String, 64);
    stack_free(String, &str);
  }

}
