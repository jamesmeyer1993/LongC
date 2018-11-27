#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <longc/lang.h>

#include "../string.h"

#define TEST_TEXT_00 \
  "Voilà! In view, a humble vaudevillian veteran cast vicariously as both" \
  "victim and villain by the vicissitudes of Fate. This visage, no mere veneer" \
  "of vanity, is a vestige of the vox populi, now vacant, vanished. However, " \
  "this valourous visitation of a bygone vexation stands vivified and has" \
  "vowed to vanquish these venal and virulent vermin vanguarding vice and" \
  "vouchsafing the violently vicious and voracious violation of volition!" \
  "The only verdict is vengeance; a vendetta held as a votive, not in vain," \
  "for the value and veracity of such shall one day vindicate the vigilant and" \
  "the virtuous. Verily, this vichyssoise of verbiage veers most verbose, so " \
  "let me simply add that it's my very good honour to meet you and you may " \
  "call me V."

#define TEST_TEXT_01 \
  "Remember, remember!\n" \
  "The fifth of November,\n" \
  "The Gunpowder treason and plot;\n" \
  "I know of no reason\n" \
  "Why the Gunpowder treason\n" \
  "Should ever be forgot!\n"

/* TEST 0
  for new_string()
*/
void test_00() {
  String *s = new_string();
  assert(s->len == 0 && s->capacity == 8);
  free_string(s);
  printf("test 00 passed!\n");
}

/* TEST 1
  for new_string_with_capacity(...)
*/
void test_01() {
  String *s = new_string_with_capacity(64);
  assert(s->len == 0 && s->capacity == 64);
  free_string(s);
  printf("test 01 passed!\n");
}

/* TEST 2
  for new_string_from(...)
*/
void test_02() {
  const char *phrase = "Cellar door";
  String *s = new_string_from("Cellar door");
  assert(s->len == strlen(phrase));
  assert(s->capacity == strlen(phrase) + 1);
  assert(memcmp(s->c, phrase, s->len) == 0);
  printf("Test 02 passed!\t%s\n", s->c);
  free_string(s);
}

/* TEST 3
  for init_string(...)
*/
void test_03() {
  String s;
  init_string(&s);
  assert(s.len == 0 && s.capacity == 8);
  printf("Test 03 passed!\n");
  free(s.c);
}

/* TEST 4
  for init_string_from(...)
*/
void test_04() {
  const char *msg = "Mercator in foro laborat.";
  String s;
  init_string_from(&s, "Mercator in foro laborat.");
  assert(s.len == strlen(msg));
  assert(s.capacity == strlen(msg) + 1);
  for(u32 i = 0; i < strlen(msg); i++){
    assert(s.c[i] == msg[i]);
  }
  printf("Test 04 passed!\t%s\n", s.c);
  free(s.c);
}

/*  TEST 5
    for string_cmpr(...)
*/
void test_05() {
  String s1;
  String s2;
  init_string_from(&s1, "Hello world!");
  init_string_from(&s2, "Hello C");

  assert(string_cmpr(&s1, &s2) == 1);
  assert(string_cmpr(&s2, &s1) == -1);

  free(s2.c);
  init_string_from(&s2, "HELLO WORLD?");

  assert(string_cmpr(&s1, &s2) == 1);
  assert(string_cmpr(&s2, &s1) == -1);

  free(s2.c);
  init_string_from(&s2, "Hello world!");

  assert(string_cmpr(&s1, &s2) == 0);
  free(s1.c);
  free(s2.c);

  printf("Test 05 passed!\n");
}

/* TEST 6
  for string_eq(...)
*/
void test_06() {
  String s1;
  String s2;
  init_string_from(&s1, TEST_TEXT_00);
  init_string_from(&s2, TEST_TEXT_01);

  assert(string_eq(&s1, &s2) == 0);
  assert(string_eq(&s1, &s2) == false);

  free(s2.c);
  init_string_from(&s2, TEST_TEXT_00);

  assert(string_eq(&s1, &s2) == 1);
  assert(string_eq(&s1, &s2) == true);

  free(s1.c);
  free(s2.c);
  printf("Test_06 passed!\n");
}

/* TEST 7
  for string_concat
*/
void test_07() {
  String s1;
  init_string_from(&s1, "Testing... testing 1,2,3\n");
  String s2;
  init_string_from(&s2, TEST_TEXT_00);
  string_concat(&s1, &s2);

  printf("\n%s\n", s1.c);
  free(s1.c);
  free(s2.c);
  printf("Test_07 passed!\n");
}

/* TEST 8
  for string_clone
*/
void test_08() {
  String* original = new_string_from(TEST_TEXT_00);
  String* copy = string_clone(original);

  assert(string_eq(copy, original));
  free_string(original);
  free_string(copy);
  printf("Test_08 passed!\n");
}

/* TEST 9
  for string_substr(...)
*/
void test_09() {
  String* original = new_string_from(TEST_TEXT_00);

  u32 x1 = 0;
  u32 x2 = original->len >> 1;

  String* copy = string_substr(original, x1, x2);

  assert( !string_eq(original, copy) );
  assert( string_cmpr(copy, original) == -1 );
  assert( strncmp(original->c, copy->c, x2 - 1) == 0 );

  printf("--- TEST 09 ---\n" \
    "\noriginal:\n%s" \
    "\ncopy:\n%s\n",
    original->c, copy->c);

  free_string(original);
  free_string(copy);
  printf("Test_09 passed!\n");
}

void test_10() {
  String* s1 = new_string_with_capacity(1024);
  String s2;
  init_string_from(&s2, "The following is an exerpt from a film:\n");
  string_concat(s1, &s2);
  free(s2.c);
  init_string_from(&s2, TEST_TEXT_01);
  string_concat(s1, &s2);
  free(s2.c);

  printf("\n--- TEST 10 ---\n" \
    "\nUnmodified:\t%s\n\n", s1->c);

  u32 check_len = s1->len;

  string_shift(s1, -61);
  printf("\nShift by -64:\t%s\n\n", s1->c);
  check_len-=61;

  string_shift(s1, 37);
  printf("\nShift by 37:\t%s\n\n", s1->c);
  check_len+=37;

  assert(s1->len == check_len);
  assert(s1->capacity == 1024);

  free_string(s1);
  printf("Test 10 Passed!\n");
}

void test_11() {
  const char *test = "Testing. testing. 1, 2, 3. Where is the string?";
  String* s = new_string_from(test);

  {
    String* t = new_string_from("Test");
    assert( string_index_of(s, t) == 0 );

    memcpy(t->c, "test", 4);
    assert( string_index_of(s, t) == 9 );
    free_string(t);
  }

  {
    String* t = new_string_from(test);

    string_shift(t, -1);
    assert( string_index_of(s, t) == 1 );

    string_shift(t, -9);
    assert( string_index_of(s, t) == 10 );

    string_shift(t, -20);
    assert( string_index_of(s, t) == 30 );

    free_string(t);
  }

  {
    String* t = new_string_from("1,2,3");
    assert( string_index_of(s, t) == -1 );
    free_string(t);
  }

  free_string(s);
  printf("Test 11 Passed!\n");
}

void test_12(){
  String* s = new_string_from("There are many empty strings but this is not one.");

  {
    String t;
    init_string_from(&t, "not one.");
    assert( string_ends_with(s, &t) );
    free(t.c);
  }

  {
    String t;
    init_string_from(&t, "!APPLE!");
    assert( !string_ends_with(s, &t) );
    free(t.c);
  }

  free_string(s);
  printf("Test 12 Passed!\n");
}

void test_13() {

  String* s = new_string_from("A wizzard is never late - nor is he early. \
    He arrives percicely when he means to!");

  {
    String s1;
    init_string_from(&s1, "A wizzard");
    assert( string_starts_with(s, &s1) );

    String s2;
    init_string_from(&s2, " is never late");
    string_concat(&s1, &s2);
    assert( string_starts_with(s, &s1) );
    assert( !string_starts_with(s, &s2) );

    free(s1.c);
    free(s2.c);
  }

  {
    String* s1 = string_substr(s, 0, 50);
    assert( string_starts_with(s, s1) );
    free_string(s1);
  }

  {
    String* s1 = string_substr(s, 10, s->len);
    assert( !string_starts_with(s, s1) );
    free_string(s1);
  }

  free_string(s);
  printf("Test 13 passed!\n");
}

i32 main(void){
  test_00(); // passed!
  test_01(); // passed!
  test_02(); // passed!
  test_03(); // passed!
  test_04(); // passed!
  test_05(); // passed!
  test_06(); // passed!
  test_07(); // passed!
  test_08(); // passed!
  test_09(); // passed!
  test_10(); // passed!
  test_11(); // passed!
  test_12(); // passed!
  test_13(); // passed!
}
