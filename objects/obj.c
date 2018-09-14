/*
 * obj.c
 *
 *  Created on: Aug 15, 2018
 *      Author: james
 */

#include "obj.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int primes[] = {2,3,5,7,11,13,17,19,21,23,29,31,37,41,43,47,51,53,59,61,67,71,73,79,83,87};
unsigned int prevgen = 0;

unsigned long long genhashID()
{
	if(prevgen == 0){
		srand(time(NULL));
		prevgen = (int)rand() % 51;
	}
	unsigned long long gen = primes[prevgen] * prevgen;
	gen = (gen | prevgen) + (gen & prevgen) + (gen >> 1);
	prevgen = gen;
	printf("%d", (int)gen);
	return gen;
}


void obj_init(obj* src)
{
	src->hashID = genhashID;
}

obj* obj_new()
{
	obj* src = malloc(sizeof(obj));
	src->hashID = (unsigned long long)rand();
	return src;
}

void obj_destroy(obj* src)
{
	free(src);
}

char* obj_toString(obj* src)
{
	char* str = malloc(32);
	sprintf(str,"%lu", src->hashID);
	return str;
}

bool obj_equals(obj* a, obj* b)
{
	if(a->hashID == b->hashID)
		return true;
	return false;
}

int obj_compareTo(obj* a, obj* b)
{
	if(a->hashID > b->hashID)
		return 1;
	else if(a->hashID < b->hashID)
		return -1;
	else
		return 0;
}

obj* obj_clone(obj* src)
{
	obj* result = malloc(sizeof(obj));
	result->hashID = src->hashID;
	return result;
}

void obj_copy(obj* src, obj* dest)
{
	if(src == NULL || dest == NULL)
		exit(EXIT_FAILURE);

	dest->hashID = src->hashID;
}
