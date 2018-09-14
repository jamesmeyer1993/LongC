/* local imports */
#include "../types.h"
#include "../object.h"

#define WORD_CAPACITY 64  /* words have a fixed capacity of 64 bytes */

struct Word_ {
  Object* super;
  int length;
  char[WORD_CAPACITY] value;
};

typedef struct Word_ Word;

Word * initWord(void * parameters); /* constructor */
void wordDestroy(Word * word);  /* destructor */

/* getters */
int wordLength(Word * word);
char wordCharAt(Word * word, int index);  /* returns the char at a given index */
int wordContains(Word * word, char c);  /* returns number of occurances of 'c' */

/* setters */
void wordSet(char **string, int length);
void wordAddtoFront(Word * word, char c);
void wordAddtoRear(Word * word, char c);
void wordAddAt(Word * word, int index);

void wordClear(Word *word);
void wordRemove(char c);
void wordRemoveAt(int index);
