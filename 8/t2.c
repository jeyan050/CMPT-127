#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "point_array.h"

/*
typedef struct point
{
  double x, y, z;
} point_t;

typedef struct 
{
  // number of points in the array
  size_t len;
  
  // pointer to an array of point_t structs
  // There is space for 'reserved' point_t structs, 
  // but 'len' point_t structs have been used so far.
  point_t* points;
  
  // to be discussed in class - see Demo
  size_t reserved; 
  
} point_array_t;
*/

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS NULL */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	if (pa != NULL){
		assert(pa);
		pa->len = 0;
		pa->reserved = 0;
		pa->points = realloc(pa->points, sizeof(point_t));
	}
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa ){
	if (pa != NULL){
		free(pa->points);
		pa->len = 0;
		pa->reserved = 0;
		pa->points = NULL;
		free(pa);
		pa = NULL;
	}
}

// Append a point to the end of an array. If successful, return 0, else return 1.
// INt is 2 bits
int point_array_append( point_array_t* pa, point_t* p ){
		if (pa == NULL || pa->points == NULL || p == NULL){

		return 1;	

	}

	if (pa->len == 0){
		pa->len=1;
		pa->points = realloc(pa->points,sizeof(point_t)*pa->len*2);
		pa->reserved = 2;
		pa->points[pa->len] = *p;
	} else {
		pa->points[pa->len] = *p;
		pa->len = pa->len+1;
	}

	if (pa->reserved == pa->len ){
		pa->reserved = pa->reserved * 2;
		pa->points = realloc(pa->points,sizeof(point_t)*pa->reserved);
	}	
	return 0;
}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i ){
	if (pa->len <= i || pa->len == 0 || pa == NULL){
		return 1;	
	}
	pa->points[i] = pa->points[pa->len - 1];
	pa->len--;
	return 0;
}


