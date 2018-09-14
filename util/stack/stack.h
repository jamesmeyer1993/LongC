/*
 * stack.h
 *
 *  Created on: Aug 24, 2018
 *      Author: james
 */

#ifndef STACK_H_
#define STACK_H_

struct node {
	struct node* next;
	struct node* prev;
	void* elem;
};

struct stack {
	struct node* head;
	int size;
	int capacity;
};

void stack_push(struct stack* self, void* item);

void* stack_pop(struct stack* self);

void* stack_peek(struct stack* self);

#endif /* STACK_H_ */
