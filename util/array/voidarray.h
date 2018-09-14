/*
 * array.h
 *
 *  Created on: Aug 24, 2018
 *      Author: james
 */

#ifndef _VOID_ARRAY_H_
#define _VOID_ARRAY_H_

struct array {
	void* elem;
	unsigned int used;
	unsigned int capacity;
	unsigned int resizable;
	unsigned int overwrite;
};

void init_array(struct array* self);

void init_array1(struct array* self, int capacity);

void init_array2(struct array* self, void* list, int listsize);

struct array* new_array();

struct array* new_array1(int capacity);

struct array* new_array2(void* list, int listsize);

int array_add(void* elem);

int array_addat(void* elem, int index);

int array_concat(struct array* dest, struct array* src);

int array_overwrite(void* elem, int index);

int array_remove(void* elem);

int array_locate(void* elem);

int array_contains(void* elem);

int array_verify(struct array* self);	// checks data integrity

int array_trim(struct array* self);

#endif /* ARRAY_H_ */
