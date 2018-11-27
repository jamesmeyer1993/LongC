/*
 * array.h
 *
 *  Created on: Jul 30, 2018
 *      Author: james
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "longc/lang.h"
#include "longc/collection.h"

typedef struct array {
	struct {
		u32 length;
		u32 capacity;
		void *data;
	} priv;
} array;

const u32 array_getlen(array *self);

const u32 array_getcap(array *self);

const void* array_getref(array *self);

#define array_at( INDEX ) priv.data[ INDEX ]

// ----------------------------
// macros for generic functions
// ----------------------------

/* Generic Functions
These functions need only be declared here. They are to be used as on the fly
type arguments.
*/

/* array_init
	Creates an array of T on the stack.
*/
#define array_init( T , capacity ) \
	T ## array_init( (capacity) )

/* array_new
	Creates an array of T on the heap.
*/
#define array_new( T , capacity ) \
	T ## array_new( (capacity) )

/* array_free
	Deallocates an array created on the heap
*/
#define array_free( T , self ) \
	T ## array_free( (self) )

/* array_equals
	Compares two arrays.
	@returns 1 for equal, 0 for unequal
*/
#define array_equals( T , self , other ) \
	T ## array_equals( (self) , (other) )

/* array_compare
	Compares two arrays.
	@returns 0 for equals, 1 if self > other, -1 if self < other
*/
#define array_compare( T , self , other ) \
	T ## array_compare( (self) , (other) )

/* array_clone
	Performs a deep copy of the array and @returns a new array on the heap.
*/
#define array_clone( T , self ) \
	T ## array_clone( (self) )

/* array_add
	Adds an element of T to the array. If the number of elements exceeds
	the array's capacity, it will automatically resize.
*/
#define array_add( T , self , elem ) \
	T ## array_add( (self) , (elem) )

/* array_add_at
	Adds an element of T at the location of index to the array. This method
	will not write over any elements. Instead, if a write over would normally
	take place, the array will shift the elements to make room for the new
	element.
*/
#define array_add_at( T , self , index , elem ) \
	T ## array_add_at( (self) , (index) , (elem) )

/* array_remove
	Removes a specific element from the array. If this element is not the ending
	element, all following elements will have to shift back by one index
*/
#define array_remove( T , self , elem ) \
	T ## array_remove( (self) , (elem) )

/* array_remove_at
	Removes a specific element at index.
*/
#define array_remove_at( T , self , index ) \
	T ## array_remove_at( (self) , (elem) )

/* array_indexof
	Returns the index of a specific element or -1 if it cannot be located
*/
#define array_indexof( T , self , elem ) \
	T ## array_indexof( (self) , (elem) )

/* array_trim
	Reduces the capacity of the array so that length and capacity are equal
*/
#define array_trim( T , self ) \
	T ## array_tim( (self) )

/* array_clear
	Deallocates the entire array. Returns capacity and length to their default
	constructor values.
*/
#define array_clear( T , self ) \
	T ## array_clear( (self) )

// --------------------------------
// end macros for generic functions
// --------------------------------


// -----------------------------
// header file generating macros
// -----------------------------

/* The following macros are for generating template header files.
	First, we typedef an array of this type.*/
#define DEF_TYPE_ARRAY_OF( T ) \
typedef struct T ## array { \
	struct { \
		u32 length; \
		u32 capacity; \
		T* data; \
	} priv; \
} T ## array;

#define DEF_FN_ARRAY_NEW( T ) \
T ## array* \
T ## array_new(u32 cap);

#define DEF_FN_ARRAY_INIT( T ) \
T ## array \
T ## array_init( u32 capacity );

#define DEF_FN_ARRAY_FREE( T ) \
void \
T ## array_free( T ## array* self );

#define DEF_FN_ARRAY_EQUALS( T ) \
u32 \
T ## array_equals( T *self , T *other );

#define DEF_FN_ARRAY_COMPARE( T ) \
i32 \
T ## array_compare( T *self , T *other );

#define DEF_FN_ARRAY_CLONE( T ) \
T ## array* \
T ## array_clone(T ## array *self);

#define DEF_FN_ARRAY_ADD( T ) \
void \
T ## array_add( T ## array *self , T elem );

#define DEF_FN_ARRAY_ADD_AT( T ) \
void \
T ## array_add_at( T ## array *self , u32 index , T elem );

#define DEF_FN_ARRAY_REMOVE( T ) \
T \
T ## array_remove( T ## array *self , T elem );

#define DEF_FN_ARRAY_REMOVE_AT( T ) \
T \
T ## array_remove_at( T ## array *self , T *elem );

#define DEF_FN_ARRAY_INDEXOF( T ) \
u32 \
T ## array_indexof( T ## array *self , T *elem );

#define DEF_FN_ARRAY_TRIM( T ) \
void \
T ## array_tim( T ## array *self );

#define DEF_FN_ARRAY_CLEAR( T ) \
void \
T ## array_clear( T ## array *self );


/* Wrap up those in a DEF_H_... macro and we can generate a
whole header file in one line. */
#define DEF_H_ARRAY( T ) \
	DEF_TYPE_ARRAY_OF(T) \
	DEF_FN_ARRAY_INIT(T) \
	DEF_FN_ARRAY_NEW(T) \
	DEF_FN_ARRAY_FREE(T) \
	DEF_FN_ARRAY_EQUALS(T) \
	DEF_FN_ARRAY_COMPARE(T) \
	DEF_FN_ARRAY_CLONE(T) \
	DEF_FN_ARRAY_ADD(T) \
	DEF_FN_ARRAY_ADD_AT(T) \
	DEF_FN_ARRAY_REMOVE(T) \
	DEF_FN_ARRAY_REMOVE_AT(T) \
	DEF_FN_ARRAY_INDEXOF(T) \
	DEF_FN_ARRAY_TRIM(T) \
	DEF_FN_ARRAY_CLEAR(T)

// ----------------------------
// end header generating macros
// ----------------------------

// ----------------------------
// C file generating macros
// ----------------------------

#define DEF_C_FN_ARRAY_INIT( T ) \
T ## array \
T ## array_init(u32 capacity) { \
	T ## array src; \
	return src; \
}

#define DEF_C_FN_ARRAY_NEW( T ) \
T ## array* \
T ## array_new(u32 capacity) \
{ \
	T ## array* src = malloc( sizeof( T ## array ) ); \
	src->priv.data = malloc( sizeof( T ) * (capacity) ); \
	src->priv.capacity = (capacity); \
	src->priv.length = 0; \
	return src; \
}

#define DEF_C_FN_ARRAY_FREE( T ) \
void \
T ## array_free( T ## array* src ) \
{ \
	free(src->priv.data); \
	free(src); \
}

#define DEF_C_ARRAY_EQUALS( T ) \
	u32 \
	T ## array_equals( T ## array *self , T ## array *other ){ \
		if(self->priv.data == other->priv.data){ \
			return 1; \
		} \
		else if(self->priv.length != other->priv.length){ \
			return 0; \
		}else{ \
			for(u32 i = 0; i < (self->priv.length + other->priv.length)/2; i++){ \
				if(self->at(i) != other->at(i)){ \
					return 0; \
				} \
			} \
			return 1; \
		} \
	}

#define DEF_C_ARRAY_COMPARE( T ) \
i32 \
T ## array_compare( T *self , T *other ){
	()
}

#define DEF_C_ARRAY_CLONE( T ) \
T ## array* \
T ## array_clone(T ## array *self){}

#define DEF_C_ARRAY_ADD( T ) \
void \
T ## array_add( T ## array *self , T elem ){}

#define DEF_C_ARRAY_ADD_AT( T ) \
void \
T ## array_add_at( T ## array *self , u32 index , T elem ){}

#define DEF_C_ARRAY_REMOVE( T ) \
T \
T ## array_remove( T ## array *self , T elem ){}

#define DEF_C_ARRAY_REMOVE_AT( T ) \
T \
T ## array_remove_at( T ## array *self , T *elem ){}

#define DEF_C_ARRAY_INDEXOF( T ) \
u32 \
T ## array_indexof( T ## array *self , T *elem ){}

#define DEF_C_ARRAY_TRIM( T ) \
void \
T ## array_tim( T ## array *self ){}

#define DEF_C_ARRAY_CLEAR( T ) \
void \
T ## array_clear( T ## array *self ){}

// Roll up the array into one macro. This, plus the proper includes, are all
// you need to generate a strong type.
#define DEF_C_ARRAY( T ) \
	DEF_C_FN_ARRAY_NEW( T ) \
	DEF_C_FN_ARRAY_INIT( T ) \
	DEF_C_FN_ARRAY_FREE( T ) \
	DEF_C_FN_ARRAY_REMOVE( T )

// ----------------------------
// End C file generating macros
// ----------------------------

#endif /* ARRAY_H_ */
