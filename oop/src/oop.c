/*
 ============================================================================
 Name        : oop.c
 Author      : James
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct obj_fn
{
	int (*equals)(struct obj*, struct obj*);
	int (*compareto)(struct obj*, struct obj*);
};

struct obj {
	unsigned long hash;
	struct fn*;
};

int obj_equals(struct obj a, struct obj b){
	if(a. == b.hash)
		return 1;
	return 0;
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
