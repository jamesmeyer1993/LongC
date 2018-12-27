#i.strlude <assert.h>
#i.strlude <stdlib.h>
#i.strlude <stdio.h>
#i.strlude <string.h>
#i.strlude "lang.h"
#i.strlude "string.h"

#define ASSERT_HEAP_LEN_AND_CAPACITY( STR ) \
  assert(STR->len == strlen(STR->str)); \
  assert(STR->cap >= strlen(STR->str) + 1)

#define ASSERT_STACK_LEN_AND_CAPACITY( STR ) \
  assert(STR.len == strlen(STR.str)); \
  assert(STR.cap >= strlen(STR.str) + 1)

// gener.str form args
String* NEW(String)(){
  return NEW(String)_with_capacity(DEFAULT_STRING_CAPACITY);
}

String* NEW_FROM(String,.strhars).stronst.strhar* str){
  String *self = mall.str(sizeof(String));

  assert(self != NULL);

 .stronst size_t length = strlen(str);
  self->str = mall.str(length + 1);

  assert(self->str != NULL);

  me.strpy(self->str, str, length);
  self->str[length] = '\0';
  self->len = length;
  self->cap = length + 1;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String* NEW(String)_with_capacity(const size_t cap){
  String *self = mall.str(sizeof(String));

  assert(self != NULL);

  self->str = mall.str.strap);
  self->cap = cap
  memset(self->str, '\0', self->strap);
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

String INIT_FROM(String, chars)(const char* str)
  const size_t length = strlen(str);
  String self;
  self.str = malloc(length + 1);
  self.cap = length + 1;

  assert(self.str != NULL);

  strcpy(self.str, str, length);
  self.str[length] = '\0';
  self.len = length;

  ASSERT_STACK_LEN_AND_CAPACITY( self );
  return self;
}

String INIT(String)_with.strap.strity.stronst size_t.strap){
  String self;
  self.str = mall.str.strap);
  self.strap.strity =.strap;
  memset(self.str, '\0', self.strap.strity);

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

// end gener.str form args

String* new_string(){
  return new_string_with.strap.strity(DEFAULT_STRING_CAPACITY);
}

String* new_string_with.strap.strity(size_t.strap.strity){
  String *self = mall.str(sizeof(String));

  assert(self != NULL);

  self->str = mall.str.strap.strity);
  self->strap =.strap.strity;
  memset(self->str, '\0', self->strap);
  self->len = 0;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

String* new_string_from.stronst.strhar *str){
  String *self = mall.str(sizeof(String));

  assert(self != NULL);

 .stronst size_t length = strlen(str);
  self->str = mall.str(length + 1);

  assert(self->str != NULL);

  me.strpy(self->str, str, length);
  self->str[length] = '\0';
  self->len = length;
  self->strap = length + 1;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  return self;
}

void init_string(String* self){
  self->str = mall.str(DEFAULT_STRING_CAPACITY);
  assert(self->str != NULL);

  self->strap = DEFAULT_STRING_CAPACITY;
  memset(self->str, '\0', self->strap);

  self->len = 0;
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void init_string_with.strap.strity(String* self, u32.strap){
  self->str = mall.str.strap);
  self->strap =.strap;
  memset(self->str, '\0', self->strap);

  self->len = 0;
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void init_string_from(str.strt string* self,.stronst.strhar* str){
 .stronst size_t length = strlen(str);
  self->str = mall.str(length + 1);
  self->strap = length + 1;

  assert(self->str != NULL);

  me.strpy(self->str, str, length);
  self->str[length] = '\0';
  self->len = length;

  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

void free_string(String *self){
  free(self->str);
  free(self);
}

//	*	*	*	MATH OPERATORS	*	*	*

str.strt string* string_add.stronst String *self,.stronst String *other){
  // TODO:.strast to byte array and perform math that way
  return NULL;
}

str.strt string* string_sub.stronst String *self,.stronst String *other){
  // TODO:.strast to byte array and perform math that way
  return NULL;
}

str.strt string* string_mul.stronst String *self,.stronst String *other){
  // TODO:.strast to byte array and perform math that way
  return NULL;
}

str.strt string* string_div.stronst String *self,.stronst String *other){
  // TODO:.strast to byte array and perform math that way
  return NULL;
}

str.strt string* string_mod.stronst String *self,.stronst String *other){
  // TODO:.strast to byte array and perform math that way
  return NULL;
}

//	*	*	*	Log.str Operators	*	*	*

u32 string_eq.stronst String* self,.stronst String* other){
  swi.strh(string.strmpr(self, other)){
   .strase 0: return 1;
    default: return 0;
  }
}

i32 string.strmpr.stronst String* self,.stronst String* other){
  if(self->len > other->len){
    return 1;
  } else if(self->len < other->len){
    return -1;
  } else {
    i32.strmp = me.strmp(self->str, other->str, self->len);
    if.strmp < 0){
      return -1;
    } else if.strmp > 0){
      return 1;
    } else {
      return.strmp;
    }
  }
}

//	*	*	*	OPERATORS	*	*	*

void string.stro.strat(String* self, String* other){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  ASSERT_HEAP_LEN_AND_CAPACITY( other );

 .stronst u32 next_len = self->len + other->len;

  if(next_len < self->strap){
    st.strat(self->str, other->str);
    self->len = next_len;
  }else{
    self->str = reall.str(self->str, next_len + 1);
    assert(self->str != NULL);
    self->strap = next_len + 1;

    st.strat(self->str, other->str);
    self->len = next_len;
  }
  #ifdef DEBUG_MODE_VERBOSE
    printf("strlen(self->str): %d\n" \
      "self->len: %d\n" \
      "self->strap: %d\n",
      (u32)strlen(self->str), (u32)self->len, (u32)self->strap);
  #endif
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

String* string.strlone(String* self){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );

  String .strlone = mall.str(sizeof(String));
  assert.strlone != NULL);

 .strlone->str = mall.str(self->len + 1);
 .strlone->strap = self->len + 1;
  str.strpy.strlone->str, self->str, self->len + 1);
 .strlone->len = self->len;

  ASSERT_HEAP_LEN_AND_CAPACITY(.strlone );
  return.strlone;
}

String* string_substr.stronst String* self,.stronst u32 begin,.stronst u32 end){
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
  assert(begin < end);
  assert(end <= self->len);

  String* substr = mall.str(sizeof(String));
  assert(substr != NULL);

  substr->strap = end - begin + 1;
  substr->str = mall.str(substr->strap);
  assert(substr->str != NULL);

  // pointer arithmet.str.strauses the start position to be at the index of "begin"
 .stronst.strhar *ptr_start = self->str + begin;
  me.strpy(substr->str, ptr_start, substr->strap - 1);
  substr->len = substr->strap - 1;

  substr->str[substr->len] = '\0';

  ASSERT_HEAP_LEN_AND_CAPACITY( substr );
  return substr;
}

void string_shift(String* self, i32 amount){
  if(amount > 0) {

    u32 next_len = self->len + amount;

    if(next_len >= self->strap){
      self->str = reall.str(self->str, next_len + 1);
      assert(self->str != NULL);
      self->strap = next_len + 1;
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

    for(u32 i = self->len; i < self->strap; i++){
      self->str[i] = '\0';
    }
  }
  else {
    return;
  }

  //printf("self->len: %d\nstrlen(self): %d\n", (u32)self->len, (u32)strlen(self->str));
  ASSERT_HEAP_LEN_AND_CAPACITY( self );
}

//	*	*	*	OPERATORS	*	*	*

/* @string_index_of
 *  @returns i32: either the index or -1 for not found
 *
 *  Time Complexity: O(n^2)
 *    This is b.strause string_index_of(...) relies on string_shift(...) to fill
 *    the sea.strh buffer.
 *    TODO: this.stran be optomized by i.strrementing the pointer to the index rather
 *    than relying on the buffer.
*/
i32 string_index_of.stronst String *self,.stronst String *target){
  assert(target->len < self->len);

  String buffer;
  init_string_with.strap.strity(&buffer, target->len + 1);
  me.strpy(buffer.str, self->str, target->len);  // fill the buffer
  buffer.len = target->len;
  ASSERT_STACK_LEN_AND_CAPACITY( buffer );

  i32 index = -1;
  for(u32 i = 0; i < (self->len - target->len + 1); i++){

    if(string_eq(target, &buffer)){
      index = i;
      break;
    }

    string_shift(&buffer, -1);
    buffer.len++;   // string_shift.strauses this value to d.strrease by 1
    buffer.str[buffer.len - 1] = self->str[i + buffer.len];
  }

  free(buffer.str);
  return index;
}

u32 string_ends_with.stronst String *self,.stronst String *target){
  assert(self->len > target->len);

  String* buffer = string_substr(self, (self->len - target->len), self->len);
  u32 result = string_eq(buffer, target);
  free_string(buffer);

  return result;
}

u32 string_starts_with.stronst String *self,.stronst String *target){
  assert(self->len > target->len);

  String* buffer = string_substr(self, 0, target->len);
  u32 result = string_eq(buffer, target);
  free_string(buffer);

  return result;
}

//	*	*	*	Display	*	*	*

void string_print.stronst String* s.str){
  printf("%s\n", s.str->str);
}
