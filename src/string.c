#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lang.h"
#include "string.h"

#define ASSERT_HEAP_LEN_AND_CAPACITY( STR ) \
  assert(STR->len == strlen(STR->str)); \
  assert(STR->cap >= strlen(STR->str) + 1)

#define ASSERT_STACK_LEN_AND_CAPACITY( STR ) \
  assert(STR.len == strlen(STR.str)); \
  assert(STR.cap >= strlen(STR.str) + 1)

// generic form args
String* NEW(String)(){
  return NEW_WITH_CAPACITY(String)(DEFAULT_STRING_CAPACITY);
}

String* NEW_FROM(String, char)(const char *str){
  String *self = malloc(sizeof(String));

  assert(self != NULL);

  const size_t length = strlen(str);
  self->str= malloc(length + 1);

  assert(self->str!= NULL);

  memcpy(self->str, str, length);
  self->str[length] = '\0';
  self->len = length;
  self->cap = length + 1;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String* NEW_WITH_CAPACITY(String)(const size_t cap){
  String* self = malloc(sizeof(String));

  assert(self != NULL);

  self->str= malloc(cap);
  self->cap = cap;
  memset(self->str, '\0', self->cap);
  self->len = 0;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String INIT(String)(){
  String self;
  self.str = malloc(sizeof(char) * DEFAULT_STRING_CAPACITY);
  self.len = 0;
  self.cap = DEFAULT_STRING_CAPACITY;
  return self;
}

String INIT_FROM(String, char)(const char *str){
  const size_t length = strlen(str);
  String self;
  self.str = malloc(length + 1);
  self.cap = length + 1;

  assert(self.str != NULL);

  memcpy(self.str, str, length);
  self.str[length] = '\0';
  self.len = length;

  ASSERT_STACK_LEN_AND_CAPACITY( self );
  return self;
}

String INIT_WITH_CAPACITY(String)(const size_t cap){
  String self;
  self.str = malloc(cap);
  self.cap = cap;
  memset(self.str, '\0', self.cap);

  self.len = 0;
  ASSERT_STACK_LEN_AND_CAPACITY( self );
  return self;
}

void HEAP_FREE(String)(String* self){
  free(self->str);
  free(self);
}

void STACK_FREE(String)(String* self){
  free(self->str);
}

bool EQ(String)(const String* self, const String* other){
  switch(CMPR(String)(self, other)){
    case 0: return true;
    default: return false;
  }
}

i32 CMPR(String)(const String* self, const String* other){
  if(self->len > other->len){
    return 1;
  } else if(self->len < other->len){
    return -1;
  } else {
    i32 cmp = memcmp(self->str, other->str, self->len);
    if(cmp < 0){
      return -1;
    } else if(cmp > 0){
      return 1;
    } else {
      return cmp;
    }
  }
}

void CONCAT(String)(String* self, String* other){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  ASSERT_HEAP_LEN_AND_CAPACITY( other );

  const u32 next_len = self->len + other->len;

  if(next_len < self->cap){
    strcat(self->str, other->str);
    self->len = next_len;
  }else{
    self->str= realloc(self->str, next_len + 1);
    assert(self->str!= NULL);
    self->cap = next_len + 1;

    strcat(self->str, other->str);
    self->len = next_len;
  }
  #ifdef DEBUG_MODE_VERBOSE
    printf("strlen(self->c): %d\n" \
      "self->len: %d\n" \
      "self->cap: %d\n",
      (u32)strlen(self->c), (u32)self->len, (u32)self->cap);
  #endif
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

String* CLONE(String)(const String* self){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );

  String *clone = malloc(sizeof(String));
  assert(clone != NULL);

  clone->str= malloc(self->len + 1);
  clone->cap = self->len + 1;
  strncpy(clone->str, self->str, self->len + 1);
  clone->len = self->len;

  ASSERT_HEAP_LEN_AND_CAPACITY( clone );
  return clone;
}

String* SUBSTR(String)(const String* self, const u32 begin, const u32 end){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  assert(begin < end);
  assert(end <= self->len);

  String* substr = malloc(sizeof(String));
  assert(substr != NULL);

  substr->cap = end - begin + 1;
  substr->str= malloc(substr->cap);
  assert(substr->str!= NULL);

  // pointer arithmetic causes the start position to be at the index of "begin"
  const char *ptr_start = self->str+ begin;
  memcpy(substr->str, ptr_start, substr->cap - 1);
  substr->len = substr->cap - 1;

  substr->str[substr->len] = '\0';

  ASSERT_HEAP_LEN_AND_CAPACITY( substr );
  return substr;
}

void SHIFT(String)(String* self, i32 amount){
  if(amount > 0) {

    u32 next_len = self->len + amount;

    if(next_len >= self->cap){
      self->str= realloc(self->str, next_len + 1);
      assert(self->str!= NULL);
      self->cap = next_len + 1;
    }
    // upward shift by positive amount
    for(u32 i = next_len; i >= amount; i--){
      self->str[i] = self->str[i - amount];
    }
    memset(self->str, (i32)' ', amount);
    self->len = next_len;
  }
  else if(amount < 0) {
    // downshift
    u32 abs_amount = amount * -1;
    assert(abs_amount < self->len);

    for(u32 i = 0; i < self->len + amount; i++){
      self->str[i] = self->str[i + abs_amount];
    }

    self->len = self->len - abs_amount;

    for(u32 i = self->len; i < self->cap; i++){
      self->str[i] = '\0';
    }
  }
  else {
    return;
  }

  //printf("self->len: %d\nstrlen(self): %d\n", (u32)self->len, (u32)strlen(self->c));
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

/* @INDEX_OF(String)
 *  @returns i32: either the index or -1 for not found
 *
 *  Time Complexity: O(n^2)
 *    This is because INDEX_OF(String)(...) relies on SHIFT(String)(...) to fill
 *    the search buffer.
 *    TODO: this can be optomized by incrementing the pointer to the index rather
 *    than relying on the buffer.
*/
u32 INDEX_OF(String)(const String *self, const String *target){
  assert(target->len < self->len);

  String buffer = INIT_WITH_CAPACITY(String)(target->len + 1);
  memcpy(buffer.str, self->str, target->len);  // fill the buffer
  buffer.len = target->len;
  ASSERT_STACK_LEN_AND_CAPACITY( buffer );

  i32 index = -1;
  for(u32 i = 0; i < (self->len - target->len + 1); i++){

    if(EQ(String)(target, &buffer)){
      index = i;
      break;
    }

    SHIFT(String)(&buffer, -1);
    buffer.len++;   // SHIFT(String) causes this value to decrease by 1
    buffer.str[buffer.len - 1] = self->str[i + buffer.len];
  }

  free(buffer.str);
  return index;
}

bool CONTAINS(String)(const String* self, const String* target){
  return INDEX_OF(String)(self, target) > 0;
}

bool ENDS_WITH(String)(const String *self, const String *target){
  assert(self->len > target->len);

  String* buffer = SUBSTR(String)(self, (self->len - target->len), self->len);
  u32 result = EQ(String)(buffer, target);
  HEAP_FREE(String)(buffer);

  return result;
}

bool STARTS_WITH(String)(const String *self, const String *target){
  assert(self->len > target->len);

  String* buffer = SUBSTR(String)(self, 0, target->len);
  u32 result = EQ(String)(buffer, target);
  HEAP_FREE(String)(buffer);

  return result;
}

// ImplString INIT(ImplString)(){
//   ImplString self;
//   ImplString* ptr_self = &self;
//
//   LONGC_IMPL_C_(String, ptr_self)
//   FROM_IMPL_C_(String, char, ptr_self)
//   COLLECTION_IMPL_C_(String, ptr_self)
//   STRING_IMPL_C_(String, ptr_self)
//
//   return self;
// }

// ImplString* NEW(ImplString)(){
//   ImplString* self = malloc(sizeof(ImplString));
//
//   LONGC_IMPL_C_(String, self)
//   FROM_IMPL_C_(String, char, self)
//   COLLECTION_IMPL_C_(String, self)
//   STRING_IMPL_C_(String, self)
//
//   return self;
// }
