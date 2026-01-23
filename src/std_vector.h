#pragma once
#include <stdlib.h>

#define SafeMalloc(size) malloc(size); if(!size) { exit(-1);} 

#define std_vector_new(type, vector)								\
struct vec##type 													\
{																	\
	type* data; 													\
	size_t allocated_size; 											\
	size_t length;	 												\
	size_t sizeoftype; 												\
} vector;															\
{																	\
	vector.allocated_size = 8; 										\
	vector.length = 0; 												\
	vector.sizeoftype = sizeof(type);								\
	vector.data = malloc(sizeof(type) * vector.allocated_size);		\
	if(!vector.data) { exit(-1); }									\
}																	

#define std_vector_resize(vector, new_size)											\
{																					\
	vector.allocated_size = new_size;												\
	void* temp = realloc(vector.data, vector.allocated_size * vector.sizeoftype);	\
	if(!temp) {exit(-1);}															\
	vector.data = temp;																\
}																					

#define std_vector_pushback(vector, value)							\
{																	\
	if(vector.length + 1 > vector.allocated_size) 					\
	{																\
		std_vector_resize(vector, vector.allocated_size * 2);		\
	}																\
	vector.data[vector.length] = value;								\
	vector.length++;												\
}

#define std_vector_free(vector) free(vector.data);