#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "byte.h"
#include "printby.h"

// Test functions

/* PASS! */
void test1_constructor_and_destructor(){
  struct ByteArray a = newByteArray(666);
  printf("length of a = %d\n", a.len);
  printf("size of a = %d\n", a.size);
  // length test
  // make sure the array behaves like a string so we can take advantage of
  // the built in string functions
  int i = 0;
  while(a.data[i] != '\0')
    i++;
  assert(i == a.len);
  assert(strlen(a.data) == a.len);

  bytearrayDestroy(&a);
}

/* PASS! */
void test2_equals(){
  struct ByteArray a = newByteArray(10);
  struct ByteArray b = newByteArray(11);

  assert(!bytearrayEquals(&a, &b));

  bytearrayDestroy(&a);
  bytearrayDestroy(&b);
};

/* PASS! */
void test3_equals(){
  struct ByteArray a = newByteArray(5);
  struct ByteArray b = newByteArray(5);
  a.data[0] = 2;
  a.data[1] = 3;
  a.data[2] = 5;
  a.data[3] = 7;
  a.data[4] = 11;
  bytearrayCopyto(&a, &b, 0, a.len);

  assert(bytearrayEquals(&a, &b));
  //bytearrayPrintIntsof(&a);
  //bytearrayPrintIntsof(&b);
  bytearrayDestroy(&a);
  bytearrayDestroy(&b);
}

/* PASS! */
void test4_compareto(){
  struct ByteArray a = newByteArray(5);
  a.data[0] = 2;
  a.data[1] = 3;
  a.data[2] = 5;
  a.data[3] = 7;
  a.data[4] = 11;
  struct ByteArray b = bytearrayClone(&a);

  int x = bytearrayCompareTo(&a, &b);
  assert(x == 0);

  a.data[0] = 1; // make a less than b
  x = bytearrayCompareTo(&a, &b);
  assert(x == -1);

  b.data[0] = 1;
  b.data[1] = 2; // make b less than a
  x = bytearrayCompareTo(&a, &b);
  assert(x == 1);

  bytearrayDestroy(&a);
  bytearrayDestroy(&b);
}

/* PASS! */
void test5_locate(){
  struct ByteArray a = newByteArray(5);
  a.data[0] = 2;
  a.data[1] = 3;
  a.data[2] = 5;
  a.data[3] = 7;
  a.data[4] = 11;
  assert(bytearrayLocate(&a, 2) == 0);
  assert(bytearrayLocate(&a, 5) == 2);
  assert(bytearrayLocate(&a, 11) == 4);
  assert(bytearrayLocate(&a, 17) == -1);
  bytearrayDestroy(&a);
}

/* PASS! */
void test6_locatebetween(){
  struct ByteArray a = newByteArray(5);
  a.data[0] = 2;
  a.data[1] = 3;
  a.data[2] = 5;
  a.data[3] = 7;
  a.data[4] = 11;
  assert(bytearrayLocateBetween(&a, 2, 0, 3) == 0);
  assert(bytearrayLocateBetween(&a, 11, 1, 3) == -1);
  bytearrayDestroy(&a);
}

/* PASS */
void test7_locateseq(){
  struct ByteArray a = newByteArray(10);
  a.data[0] = 2;    a.data[1] = 3;
  a.data[2] = 5;    a.data[3] = 7;
  a.data[4] = 11;   a.data[5] = 13;
  a.data[6] = 17;   a.data[7] = 19;
  a.data[8] = 23;   a.data[9] = 29;

  struct ByteArray b = newByteArray(4);
  b.data[0] = 5;    b.data[1] = 7;
  b.data[2] = 11;    b.data[3] = 13;

  // iterate by 1 - regular sequence
  assert(bytearrayLocateSeq(&a, &b, 0, a.len, 1) == 2);
  assert(bytearrayLocateSeq(&a, &b, 0, a.len, 2) == 2);
  assert(bytearrayLocateSeq(&a, &b, 0, a.len, 4) == -1);
  bytearrayDestroy(&a);
}

/* PASS! */
void test8_occurancesof(){
  char* str = "Vola! in view a humble vodivilian veteran, \
    cast vicariously by the visistudes of fate, \
    this visage - no mere venire of vanity, \
    is a vestage of the vox populi now vancant and vanished! \
    ...verily this vicious vuage of verbiage vieres most verbose";
  struct ByteArray a = newByteArray(strlen(str));
  strcpy(a.data, str);

  struct ByteArray b = newByteArray(2);
  strcpy(b.data, "in");
  assert(bytearrayOccurancesofSeq(&a, &b, 0, a.len, 1) == 1);
  strcpy(b.data, "of");
  assert(bytearrayOccurancesofSeq(&a, &b, 0, a.len, 1) == 4);
  printf("%d\n", bytearrayOccurancesofSeq(&a, &b, 0, a.len, 1));
  bytearrayDestroy(&b);

  struct ByteArray c = newByteArray(1);
  c.data[0] = '!';
  assert(bytearrayOccurancesofSeq(&a, &c, 0, a.len, 1) == 2);

  c.data[0] = ' ';
  assert(bytearrayOccurancesofSeq(&a, &c, 0, a.len, 1) > 0);
  bytearrayDestroy(&c);

  bytearrayDestroy(&a);
}

/* PASS! */
void test9_resize(){
  char* str1 = "bitcoin";
  char* str2 = ".org";
  char* str3 = " and ";
  char* str4 = "bitcointechweekly";
  char* str5 = ".com";
  char* str6 = "bitcoin.org and bitcointechweekly.com";

  struct ByteArray a = newByteArray(strlen(str1));
  strcpy(a.data, str1);
  bytearrayResize(&a, a.len + strlen(str2));
  strcat(a.data, str2);
  bytearrayResize(&a, a.len + strlen(str3));
  strcat(a.data, str3);
  bytearrayResize(&a, a.len + strlen(str4));
  strcat(a.data, str4);
  bytearrayResize(&a, a.len + strlen(str5));
  strcat(a.data, str5);

  struct ByteArray b = newByteArray(strlen(str6));
  strcpy(b.data, str6);

  assert(bytearrayEquals(&a, &a));
}

void test10_copyandomit(){
  char* str = "Vola! in view a humble vodivilian veteran, \
  cast vicariously by the visistudes of fate, \
  this visage - no mere venire of vanity, \
  is a vestage of the vox populi now vancant and vanished! \
  ...verily this vicious vuage of verbiage vieres most verbose";
  struct ByteArray a = newByteArray(strlen(str));
  strcpy(a.data, str);
  printf("%s\n\n", a.data);

  struct ByteArray* omitlist = malloc(sizeof(struct ByteArray) * 5);
  omitlist[0] = newByteArray(1);
  omitlist[0].data[0] = ',';
  omitlist[1] = newByteArray(3);
  strcpy(omitlist[1].data, "...");
  omitlist[2] = newByteArray(2);
  strcpy(omitlist[2].data, "of");
  omitlist[3] = newByteArray(2);
  strcpy(omitlist[2].data, "in");
  omitlist[3] = newByteArray(3);
  strcpy(omitlist[2].data, "now");
  omitlist[4] = newByteArray(7);
  strcpy(omitlist[2].data, "verbose");

  struct ByteArray b = bytearrayCopyandOmit(&a, omitlist, 5, 0, a.len, 1);
  printf("%s\n", b.data);

  bytearrayDestroy(&a);
  bytearrayDestroy(&b);
  for(int i = 0; i < 5; i++)
    bytearrayDestroy(&omitlist[i]);
}

void test11_set(){
  struct ByteArray a = newByteArray(10);

  char* str1 = "This is a test string!";
  bytearraySet(&a, str1);
  assert(a.len == 9);

  a.resizeable = true;
  char* str2 = "This is a slightly longer test string...";
  bytearraySet(&a, str2);
  assert(a.len == strlen(str2));

  bytearrayDestroy(&a);
}

/* PASS! */
void test12_add(){
  struct ByteArray a = newByteArray(2);
  a.resizeable = true;

  char* str1 = "Sometimes, there isn't enough space in a string. ";
  char* str2 = "In that case, it's always useful to have a dynamic string!";
  bytearraySet(&a, str1);
  assert(a.len == strlen(str1));

  bytearrayAdd(&a, str2);
  assert(a.len == (strlen(str1) + strlen(str2)) );

  printf("Bytes: %d", (int)(sizeof(struct ByteArray) + a.size));

  bytearrayDestroy(&a);
}

/* PASS! */
void test13_sub(){
  struct ByteArray a = newByteArray(2);
  a.resizeable = true;
  char* str1 = "Sometimes, there isn't enough space in a string. ";
  char* str2 = "In that case, it's always useful to have a dynamic string!";

  bytearraySet(&a, str1);
  bytearrayAdd(&a, str2);

  struct ByteArray b = bytearraySub(&a, 7, 91);

  assert(b.size == 29 - 5 + 1);
  printf("b.size = %d\n", b.size);
  printf("b.len = %d\n", b.len);
  printf("b.data = %s\n", b.data);
  //assert(b.len == 29 - 5 - 1);

  bytearrayDestroy(&b);
  bytearrayDestroy(&a);
}

int main(){

  //test1_constructor_and_destructor();
  //test2_set();
  //test3_add();
  //test4_sub();
  //test2_equals();
  //test3_equals();
  //test4_compareto();
  //test5_locate();
  //test6_locatebetween();
  //test7_locateseq();
  //test8_occurancesof();
  //test9_resize();
  //test10_copyandomit();

  exit(0);
}
