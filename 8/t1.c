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

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	if (pa != NULL){
		assert(pa);
		pa->len = 0;
		pa->points = realloc(pa->points, sizeof(point_t));
	}
	
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa ){
	if (pa != NULL){
		free(pa->points);
		pa->len = 0;
		pa->points = NULL;
		free(pa);
		pa = NULL;
		return;
	}
}

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p ){
	if (pa == NULL || pa->points == NULL || p == NULL){
		return 1;	
	}
	int origLen = pa->len;
	pa->len = origLen+1;
	pa->points = realloc(pa->points, sizeof(point_t)*pa->len);
	pa->points[origLen] = *p;
	/*
	OR
	pa->points[origLen].x = p->x;
	pa->points[origLen].y = p->y;
	pa->points[origLen].z = p->z;
	*/
	return 0;
}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i ){
	if (pa == NULL || pa->points == NULL || pa->len <= i){
		return 1;
	}
	pa->points[i] = pa->points[pa->len-1];
	pa->len--;
	pa->points = realloc(pa->points, sizeof(point_t)*pa->len);
	return 0;
}







