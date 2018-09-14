#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "obj/obj.h"
#include "obj/type.h"
#include "obj/byte/byte.h"
#include "obj/list/node.h"
#include "obj/list/stack/stack.h"

int main(){

  char* c1 = "First byteseq";
  char* c2 = "Second byteseq";
  char* c3 = "Third byteseq";
  char* c4 = "Fourth byteseq";
  char* c5 = "Fith byte sequence...";

  struct byteseq b1 = newbyteseq(strlen(c1));
  byteseqSet(&b1, c1);
  struct byteseq b2 = newbyteseq(strlen(c2));
  byteseqSet(&b2, c2);
  struct byteseq b3 = newbyteseq(strlen(c3));
  byteseqSet(&b3, c3);
  struct byteseq b4 = newbyteseq(strlen(c4));
  byteseqSet(&b4, c4);
  struct byteseq b5 = newbyteseq(strlen(c5));
  byteseqSet(&b5, c5);

  struct stack s = newstack(T_BYTESEQ);

  struct obj arg1 = newobj(T_BYTESEQ, &b1);
  stack_push(&s, &arg1);
  struct obj arg2 = newobj(T_BYTESEQ, &b2);
  stack_push(&s, &arg2);
  struct obj arg3 = newobj(T_BYTESEQ, &b3);
  stack_push(&s, &arg3);
  struct obj arg4 = newobj(T_BYTESEQ, &b4);
  stack_push(&s, &arg4);
  struct obj arg5 = newobj(T_BYTESEQ, &b5);
  stack_push(&s, &arg5);

  printf("s.len = %d\n", s.len);
  printf("s.size = %d\n", s.size);

  byteseqDestroy(&b1);
  byteseqDestroy(&b2);
  byteseqDestroy(&b3);
  byteseqDestroy(&b4);
  byteseqDestroy(&b5);

  exit(0);
}
