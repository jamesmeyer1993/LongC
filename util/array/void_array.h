#ifndef _VOID_ARRAY_H_
#define _VOID_ARRAY_H_

#include <stdbool.h>
#include "primitives.h"

struct void_array
{
  void* at;

  // private members
  struct {
    bool mut;   // ownership: is this structure mutable?
    ui32 type;  // dynamic type
  } priv;

  struct void_array_fn* fn; // functions have to be initialized
  
};

struct void_array_fn {
  bool (*ismut)(const struct void_array* self);
  bool (*add)(const struct void_array* self, void* elem);
  bool (*addtorear)(const struct void_array* self, void* elem);
  bool (*addtofront)(const struct void_array* self, void* elem);
  bool (*addat)(const struct void_array* self, void* elem, ui32 index);
  ui32 (*type)(const struct void_array* self);
};

// functions
struct void_array* new_void_array();
struct void_array* new_void_array1(ui32 cap);

// methods
bool ismut(struct void_array* self);
//{
//  return self->priv->mut;
//}

ui32 type(struct void_array* self);
//{
//  return self->priv->type;
//}

bool add(struct void_array *self, void *elem);

bool addtofront(struct void_array *self, void *elem);

bool addtorear(struct void_array *self, void *elem);

bool addat(struct void_array *self, void *elem, ui32 index);

#endif
