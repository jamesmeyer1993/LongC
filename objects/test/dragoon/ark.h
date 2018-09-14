#include <stdbool.h>

struct ark_
{
  int size, len;
  void* ptrlist;
  bool* exits;
  int* type, size;
  void* fun_equals, fun_compareto, fun_tostring;
};

typedef struct ark_ ark;

#define NEWARK(name, elements) \
  ark* (name) = malloc(sizeof(ark)); \
  (name)->ptrlist = malloc(elements * sizeof(void*)); \
  (name)->exits = malloc(elements * sizeof(bool*)); \
  (name)->type = malloc(elements * sizeof(int*)); \
  (name)->size = malloc(elements * sizeof(int*)); \
  (name)->fun_equals = malloc(elements * sizeof(void*)); \
  (name)->fun_compareto = malloc(elements * sizeof(void*)); \
  (name)->fun_equals = malloc(elements * sizeof(void*)); \
  (name)->size = (elements); \
  (name)->len = 0

#define ARK_ADD(src, ptr, type, size, fun_equals, fun_compareto, fun_tostring) \
  ark_add( (src), (ptr), (type), (size), (fun_equals), (fun_compareto), (fun_tostring) )

void ark_add(ark* src, void* ptr, int type, int size,
            void* fun_equals,
            void* fun_compareto,
            void* fun_tostring)
{
  assert(src->len -1 < size);
  src->ptrlist[len] = ptr;
  src->fun_equals[len] = fun_equals;
  src->fun_compareto[len] = fun_compareto;
  src->fun_tostring[len] = fun_tostring;
}
