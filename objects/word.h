#ifndef _WORDH_
#define _WORDH_

#include <stddef.h>   // for NULL pointer comparisons
#include <stdbool.h>  // for booleans
#include "byte.h"

#define WORD_BYTE_LEN 32

struct Word{
  byte len;
  byte word[WORD_BYTE_LEN];
  // data processing varaibles
  int ofthistype; // only one unique variation of each word needs to be stored
  byte weight; // multiplier for probabilistic evaluations
};

// Constructor
struct Word newWord(const char *ch){
  struct Word w;
  if(ch == NULL){
    for(int i = 0; i < WORD_BYTE_LEN; i++)
      w.word[i] = '\0';
    w.len = 0;
  }else{
    for(int i = 0; i < WORD_BYTE_LEN && ch[i] != '\0'; i++){
      w.word[i] = ch[i];
      w.len++;
    }
  }
  return w;
};

// accessor
int wordSum(struct Word *w){
  int sum = 0;
  for(int i = 0; i < w->len; i++)
    sum = sum + w->word[i];
  return sum;
}

// mutator
void wordSanitize(struct Word *w)
// casts the word to lower case and removes all non-alphanumeric characters
{
  bool isend, isnum, islowercase, isuppercase;

  for(int i = 0; i < w->len; i++){
    bool isend=isnum=islowercase=isuppercase = false; // reset flags

    if(w->word[i] == '\0') isend = true;
    else if(w->word[i] >= '0' && w->word[i] <= '9') isnum = true;
    else if(w->word[i] >= 'A' && w->word[i] <= 'Z') isuppercase = true;
    else if(w->word[i] >= 'a' && w->word[i] <= 'b') islowercase = true;

    if(isuppercase) w->word[i]+=32; // cast to lower case

    if(isnum != true && isuppercase != true && islowercase != true && isend != true)
    // push all the elements from i onward back by 1
    {
      w->len--;
      for(int j = i; j < w->len; j++){
        w->word[j] = w->word[j] + 1;
      }
    }

  }

}

#endif
