#ifndef _UI8_ARRAY_H_
#define _UI8_ARRAY_H_

#include "primiitves.h"

struct ui8_array {
  ui8* at;
  ui32 len;
  ui32 capacity;
};

void init_ui8_array(struct ui8_array *src);
void init_ui8_array1(struct ui8_array *src, ui32 cap);
void init_ui8_array2(struct ui8_array *src, ui8* array, ui32 length, ui32 cap);

struct ui8_array* new_ui8_array();
struct ui8_array* new_ui8_array1(ui32 cap);
struct ui8_array* new_ui8_array2(ui8* array, ui32 length, ui32 cap);

void ui8_array_resize(struct ui8_array *src);
void ui8_array_resizeby(struct ui8_array *src, ui32 rate);
void ui8_array_resizeto(struct ui8_array *src, ui32 cap);

// ui8_array_clear
//  sets the array to zero
void ui8_array_clear(struct ui8_array *src);

// ui8_array_trim
//  sets the capacity equal to the length
void ui8_array_trim(struct ui8_array *src);

#endif
