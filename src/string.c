#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lang.h"
#include "string.h"

#define ASSERT_HEAP_LEN_AND_CAPACITY( STR ) \
  assert(STR->len == strlen(STR->c)); \
  assert(STR->capacity >= strlen(STR->c) + 1)

#define ASSERT_STACK_LEN_AND_CAPACITY( STR ) \
  assert(STR.len == strlen(STR.c)); \
  assert(STR.capacity >= strlen(STR.c) + 1)

// generic form args
String* new(String)(){
  return new_with_capacity(String, DEFAULT_STRING_CAPACITY);
}

String* new_from(String, chars, const char* str){
  String *self = malloc(sizeof(String));

  assert(self != NULL);

  const size_t length = strlen(str);
  self->c = malloc(length + 1);

  assert(self->c != NULL);

  memcpy(self->c, str, length);
  self->c[length] = '\0';
  self->len = length;
  self->capacity = length + 1;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String* new_with_capacity(String, const size_t cap){
  String *self = malloc(sizeof(String));

  assert(self != NULL);

  self->c = malloc(cap);
  self->capacity = cap;
  memset(self->c, '\0', self->capacity);
  self->len = 0;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String init(String)(){
  String self;
  self.c = malloc(sizeof(char) * DEFAULT_STRING_CAPACITY);
  self.len = 0;
  self.capacity = DEFAULT_STRING_CAPACITY;
  return self;
}

String init_from(String, chars, const char* str){
  const size_t length = strlen(str);
  String self;
  self.c = malloc(length + 1);
  self.capacity = length + 1;

  assert(self.c != NULL);

  memcpy(self.c, str, length);
  self.c[length] = '\0';
  self.len = length;

  ASSERT_STACK_LEN_AND_CAPACITY( self );
  return self;
}

String init_with_capacity(String, const size_t cap){
  String self;
  self.c = malloc(cap);
  self.capacity = cap;
  memset(self.c, '\0', self.capacity);

  self.len = 0;
  ASSERT_STACK_LEN_AND_CAPACITY( self );
  return self;
}

void heap_free(String, String* self){
  free(self->c);
  free(self);
}

void stack_free(String, String* self){
  free(self->c);
}

// end generic form args

String* new_string(){
  return new_string_with_capacity(DEFAULT_STRING_CAPACITY);
}

String* new_string_with_capacity(size_t capacity){
  String *self = malloc(sizeof(String));

  assert(self != NULL);

  self->c = malloc(capacity);
  self->capacity = capacity;
  memset(self->c, '\0', self->capacity);
  self->len = 0;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String* new_string_from(const char *str){
  String *self = malloc(sizeof(String));

  assert(self != NULL);

  const size_t length = strlen(str);
  self->c = malloc(length + 1);

  assert(self->c != NULL);

  memcpy(self->c, str, length);
  self->c[length] = '\0';
  self->len = length;
  self->capacity = length + 1;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

void init_string(String* self){
  self->c = malloc(DEFAULT_STRING_CAPACITY);
  assert(self->c != NULL);

  self->capacity = DEFAULT_STRING_CAPACITY;
  memset(self->c, '\0', self->capacity);

  self->len = 0;
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void init_string_with_capacity(String* self, u32 cap){
  self->c = malloc(cap);
  self->capacity = cap;
  memset(self->c, '\0', self->capacity);

  self->len = 0;
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void init_string_from(struct string* self, const char* str){
  const size_t length = strlen(str);
  self->c = malloc(length + 1);
  self->capacity = length + 1;

  assert(self->c != NULL);

  memcpy(self->c, str, length);
  self->c[length] = '\0';
  self->len = length;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void free_string(String *self){
  free(self->c);
  free(self);
}

//	*	*	*	MATH OPERATORS	*	*	*

struct string* string_add(const String *self, const String *other){
  // TODO: cast to byte array and perform math that way
  return NULL;
}

struct string* string_sub(const String *self, const String *other){
  // TODO: cast to byte array and perform math that way
  return NULL;
}

struct string* string_mul(const String *self, const String *other){
  // TODO: cast to byte array and perform math that way
  return NULL;
}

struct string* string_div(const String *self, const String *other){
  // TODO: cast to byte array and perform math that way
  return NULL;
}

struct string* string_mod(const String *self, const String *other){
  // TODO: cast to byte array and perform math that way
  return NULL;
}

//	*	*	*	Logic Operators	*	*	*

u32 string_eq(const String* self, const String* other){
  switch(string_cmpr(self, other)){
    case 0: return 1;
    default: return 0;
  }
}

i32 string_cmpr(const String* self, const String* other){
  if(self->len > other->len){
    return 1;
  } else if(self->len < other->len){
    return -1;
  } else {
    i32 cmp = memcmp(self->c, other->c, self->len);
    if(cmp < 0){
      return -1;
    } else if(cmp > 0){
      return 1;
    } else {
      return cmp;
    }
  }
}

//	*	*	*	OPERATORS	*	*	*

void string_concat(String* self, String* other){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  ASSERT_HEAP_LEN_AND_CAPACITY( other );

  const u32 next_len = self->len + other->len;

  if(next_len < self->capacity){
    strcat(self->c, other->c);
    self->len = next_len;
  }else{
    self->c = realloc(self->c, next_len + 1);
    assert(self->c != NULL);
    self->capacity = next_len + 1;

    strcat(self->c, other->c);
    self->len = next_len;
  }
  #ifdef DEBUG_MODE_VERBOSE
    printf("strlen(self->c): %d\n" \
      "self->len: %d\n" \
      "self->capacity: %d\n",
      (u32)strlen(self->c), (u32)self->len, (u32)self->capacity);
  #endif
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

String* string_clone(String* self){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );

  String *clone = malloc(sizeof(String));
  assert(clone != NULL);

  clone->c = malloc(self->len + 1);
  clone->capacity = self->len + 1;
  strncpy(clone->c, self->c, self->len + 1);
  clone->len = self->len;

  ASSERT_HEAP_LEN_AND_CAPACITY( clone );
  return clone;
}

String* string_substr(const String* self, const u32 begin, const u32 end){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  assert(begin < end);
  assert(end <= self->len);

  String* substr = malloc(sizeof(String));
  assert(substr != NULL);

  substr->capacity = end - begin + 1;
  substr->c = malloc(substr->capacity);
  assert(substr->c != NULL);

  // pointer arithmetic causes the start position to be at the index of "begin"
  const char *ptr_start = self->c + begin;
  memcpy(substr->c, ptr_start, substr->capacity - 1);
  substr->len = substr->capacity - 1;

  substr->c[substr->len] = '\0';

  ASSERT_HEAP_LEN_AND_CAPACITY( substr );
  return substr;
}

void string_shift(String* self, i32 amount){
  if(amount > 0) {

    u32 next_len = self->len + amount;

    if(next_len >= self->capacity){
      self->c = realloc(self->c, next_len + 1);
      assert(self->c != NULL);
      self->capacity = next_len + 1;
    }
    // upward shift by positive amount
    for(u32 i = next_len; i >= amount; i--){
      self->c[i] = self->c[i - amount];
    }
    memset(self->c, (i32)' ', amount);
    self->len = next_len;
  }
  else if(amount < 0) {
    // downshift
    u32 abs_amount = amount * -1;
    assert(abs_amount < self->len);

    for(u32 i = 0; i < self->len + amount; i++){
      self->c[i] = self->c[i + abs_amount];
    }

    self->len = self->len - abs_amount;

    for(u32 i = self->len; i < self->capacity; i++){
      self->c[i] = '\0';
    }
  }
  else {
    return;
  }

  //printf("self->len: %d\nstrlen(self): %d\n", (u32)self->len, (u32)strlen(self->c));
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

//	*	*	*	OPERATORS	*	*	*

/* @string_index_of
 *  @returns i32: either the index or -1 for not found
 *
 *  Time Complexity: O(n^2)
 *    This is because string_index_of(...) relies on string_shift(...) to fill
 *    the search buffer.
 *    TODO: this can be optomized by incrementing the pointer to the index rather
 *    than relying on the buffer.
*/
i32 string_index_of(const String *self, const String *target){
  assert(target->len < self->len);

  String buffer;
  init_string_with_capacity(&buffer, target->len + 1);
  memcpy(buffer.c, self->c, target->len);  // fill the buffer
  buffer.len = target->len;
  ASSERT_STACK_LEN_AND_CAPACITY( buffer );

  i32 index = -1;
  for(u32 i = 0; i < (self->len - target->len + 1); i++){

    if(string_eq(target, &buffer)){
      index = i;
      break;
    }

    string_shift(&buffer, -1);
    buffer.len++;   // string_shift causes this value to decrease by 1
    buffer.c[buffer.len - 1] = self->c[i + buffer.len];
  }

  free(buffer.c);
  return index;
}

u32 string_ends_with(const String *self, const String *target){
  assert(self->len > target->len);

  String* buffer = string_substr(self, (self->len - target->len), self->len);
  u32 result = string_eq(buffer, target);
  free_string(buffer);

  return result;
}

u32 string_starts_with(const String *self, const String *target){
  assert(self->len > target->len);

  String* buffer = string_substr(self, 0, target->len);
  u32 result = string_eq(buffer, target);
  free_string(buffer);

  return result;
}

//	*	*	*	Display	*	*	*

void string_print(const String* src){
  printf("%s\n", src->c);
}
