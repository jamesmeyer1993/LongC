/* types
In this file, we assign bytevalues to two data types: primitives and objects.
First, type is defined. From there, bytes are allocated based on their similarity,
like sorting a bookshelf. Objects of similarity are grouped within four bytes of one
another.
*/

typedef unsigned char type;
typedef unsigned char byte;
typedef unsigned short character; /* in case we need to use all our char stuff on utf-8 or whatever it is. */
typedef unsigned int integer;

#define T_NULL 0   /* There should be no more than 256 types defined. */

/* Primitive Types*/
#define T_BYTE 1
#define T_CHAR 2
#define T_UNSIG_CHAR 3
#define T_SHORT 4
#define T_UNSIG_SHORT 5
#define T_INT 6
#define T_UNSIG_INT 7
#define T_LONG 8
#define T_UNSIG_LONG 9
#define T_FLOAT 10
#define T_DOULBE 11
#define T_UNSIG_DOULBE 12

/* Object Types */
#define T_OBJECT 16
#define T_NODE 17 // binary by default. binary is more useful generally.
#define T_ARRAY 20 // of a fixed size... maybe 256 bytes
#define T_ARRAYLIST 21 // Dynamic:
#define T_LINKEDLIST 21 // Dynamic: linked
#define T_STACK 24 // Static: linked
#define T_QUEUE 25 // Static: linked
#define T_BINARYTREE 28 // Dynamic: linked
#define T_WORD 32 // Static: Extends from T_ARRAY
#define T_STRING 36 // Dynamic: Extends from T_ARRAY but is dynamic (unlike T_WORD)

/* Functional */
#define T_OPTIONAL 64
#define T_EXCEPTION 68
#define T_RUNTIME_EXCEPTION 69

/* Design Patern Objects */
#define T_FACTORY 0x86
