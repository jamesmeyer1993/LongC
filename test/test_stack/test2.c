#include <stdlib.h>
#include <stdio.h>
#include "../../bin/lang.h"
#include "../../bin/stack.h"

i32 main(void){

  #ifndef push
    #define push PUSH(Stack,void)
  #endif

  #ifndef pop
    #define pop POP(Stack,void)
  #endif

  #ifndef peek
    #define peek PEEK(Stack,void)
  #endif

  const char* names[] = {
    "Alice",
    "Bob",
    "Charlie",
    "Dave",
    "Edson",
    "Frank",
    "Helen"
  };

  Stack* vstack = new(Stack)(NULL);

  for(u32 i = 0; i < 7; i++){
    push(vstack, names[i]);
  }

  struct node* receive;
  for(u32 i = 0; i < 7; i++){
    receive = pop(vstack);
    printf("%s\n", (char*)receive->elem);
    free(receive);
  }

  free(vstack);

  #undef push
  #undef pop
  #undef peek
}
