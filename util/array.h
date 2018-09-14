/*
 * array.h
 *
 *  Created on: Jul 30, 2018
 *      Author: james
 */

#ifndef ARRAY_H_
#define ARRAY_H_

// generic functions
#define array_init( T , src , size ) T ## array_init( (src) , (size) )

#define array_new( T , size ) T ## array_new( (size) )

#define array_destroy( T , src ) T ## array_destroy( (src) )

#define array_set( T , src , index , obj ) T ## array_set( (src) , (index) , (obj) )

#define array_get( T , src , index ) T ## array_get( (src) , (index) )

#define array_remove( T , src , index ) T ## array_remove( (src) , (index) )

#define array_print( T , src ) \
	for(int i = 0; i < (src)->size; i++) { \
		printf("" #T "[%d]: %s\n", i , toString( T ,(src) ) );}

// generic array header
#define define_array_h( T ) \
\
	struct T ## array_ \
	{ \
		T* elem; \
		int size; \
	}; \
\
	typedef struct T ## array_ T ## array; \
\
	void T ## array_init( T* src , int size ); \
\
	T ## array* T ## array_new( int size ); \
\
	void T ## array_destroy( T ## array* src ); \
\
	void T ## array_set( T ## array* src , int index , T* obj ); \
\
	T* T ## array_get( T ## array* src , int index ); \
\
	T* T ## array_remove( T ## array* src , int index);

// generic array
#define define_array_c( T ) \
\
	void T ## array_init(T* src, int size) \
	{ \
		\
	} \
\
	T ## array* T ## array_new(int size) \
	{ \
		T ## array* src = malloc( sizeof( T##array ) ); \
		src->elem = malloc( sizeof( T ) * (size) ); \
		src->size = (size); \
		return src; \
	} \
\
	void T ## array_destroy( T##array* src ) \
	{ \
		free(src->elem); \
		free(src); \
	} \
\
	void T ## array_set( T ## array* src , int index , T* obj) \
	{ \
		if(src == NULL || index >= src->size || index < 0) exit(EXIT_FAILURE); \
		T ## _copy( obj , &src->elem[index] ); \
	} \
\
	T* T ## array_get ( T ## array* src , int index ) \
	{ \
		if(src == NULL || index >= src->size || index < 0) exit(EXIT_FAILURE); \
		T* result = &src->elem[index]; \
		return result; \
	} \
\
	T* T ## array_remove ( T ## array* src , int index ) \
	{ \
		if(src == NULL || index >= src->size || index < 0) exit(EXIT_FAILURE); \
		T* result = &src->elem[index]; \
		return result; \
	}

#endif /* ARRAY_H_ */
