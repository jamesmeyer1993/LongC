#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "obj/obj.h"
#include "obj/byte/byte.h"
#include "obj/list/list.h"
#include "obj/list/node.h"
#include "obj/list/stack/stack.h"

int main(){

  struct byteseq* b1 = newbyteseq1("First byteseq.");
  struct byteseq* b2 = newbyteseq1("Second byteseq.");
  struct byteseq* b3 = newbyteseq1("Third byteseq.");
  struct byteseq* b4 = newbyteseq1("This is the fourth byteseq!");
  struct byteseq* b5 = newbyteseq1("This is the fifth and final byteseq!!");

  struct stack* s1 = newstack(T_BYTESEQ);

  stack_push(s1, byteseq_toobj(b1));
  stack_push(s1, byteseq_toobj(b2));
  stack_push(s1, byteseq_toobj(b3));
  stack_push(s1, byteseq_toobj(b4));
  stack_push(s1, byteseq_toobj(b5));

  printf("s1.len = %d\n", s1->len);
  printf("s1.size = %d\n", s1->size);

  struct obj* generic = stack_pop(s1);
  if(generic->T == T_BYTESEQ){
    struct byteseq* seq = (struct byteseq*)generic->self;
    printf("byteseq successfully accessed:\n\t%s\n", seq->data);
  }
  obj_destroy(generic);

  printf("s1.len = %d\n", s1->len);
  printf("s1.size = %d\n", s1->size);

  generic = stack_pop(s1);
  if(generic->T == T_BYTESEQ){
    struct byteseq* seq = (struct byteseq*)generic->self;
    printf("byteseq successfully accessed:\n\t%s\n", seq->data);
  }
  obj_destroy(generic);

  printf("s1.len = %d\n", s1->len);
  printf("s1.size = %d\n", s1->size);

  foreach_node(cur, s1->head)
  {
    generic = cur->data;
    if(generic->T == T_BYTESEQ){
      struct byteseq* seq = (struct byteseq*)generic->self;
      printf("%s\n", seq->data);
    }
  }

  foreach_node_rev(cur, s1->tail){
    generic = cur->data;
    if(generic->T == T_BYTESEQ){
      struct byteseq* seq = (struct byteseq*)generic->self;
      printf("%s\n", seq->data);
    }
  }

  stack_destroy(s1);
  byteseqDestroy(b1);
  byteseqDestroy(b2);
  byteseqDestroy(b3);
  byteseqDestroy(b4);
  byteseqDestroy(b5);

  byte count = 0;
  struct obj* many = malloc(10 * sizeof(struct obj));
  foreach_obj(cur, many, 0, 10){
    cur->T = count;
    cur->self = NULL;
    count++;
  }endfor;

  foreach_obj(cur, many, 0, 10){
    printf("%d : %d\n", i,(int)cur->T);
  }endfor;

  foreach_obj_rev(cur, many, 9, 0){
    printf("%d\n", (int)cur->T);
  }endfor;

  free(many);

  exit(0);
}
