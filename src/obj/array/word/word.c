#include <stdio.h>
#include "types.h"
#include "word.h"

Word * initWord(void * parameters){

  if(parameters != NULL){
    /* TODO: handle parameters */
    printerr("Parameters are not equal to null. Exiting...");
    exit(-1);
  }
  Word *word = ( Word* ) malloc(sizeof(Word));
  word->super = initObject(T_WORD);
  word->length = 0;
  for(int i = 0; i < WORD_CAPACITY; i++)
    word->value[i]='\0';
}

void wordDestroy(Word * word){
  free(word->super);  /* Question: do I need to do this? */
  free(word);
}

/* getters */
int wordLength(Word * word){
  int l = 0;
  while(value[l] != '\0' && l < WORD_CAPACITY)
    l++;
  return l;
}

char wordCharAt(Word * word, int index){
  for()
}

int wordContains(Word * word, char c){

}

/* setters */
void wordSet(char **string, int length){
  if(length > WORD_CAPACITY){
    // TODO: better error handling
    printerr("Runtime Error: Length beyond word capacity. Exiting...");
    exit(-1);
  }
}

void wordAddtoFront(Word * word, char c){

}

void wordAddtoRear(Word * word, char c){

}

void wordAddAt(Word * word, int index){

}

void wordClear(Word *word){

}

void wordRemove(char c){

}

void wordRemoveAt(int index){

}
