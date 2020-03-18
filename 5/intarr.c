#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
	
	intarr_t *newintarr = malloc(sizeof(intarr_t));
	if ( newintarr == NULL){
		return NULL;
	}
	newintarr->len = len;
	newintarr->data = malloc(sizeof(int) * newintarr->len);
	return newintarr;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
	if (ia != NULL){
		if (ia->data != NULL){
			free(ia);		
		}	
	}
  return;
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ){
	if (ia->len > index){
		ia->data[index] = val;
		return INTARR_OK;
	} else {
		return INTARR_BADINDEX;	
	}
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
							unsigned int index, 
							int* val ){
	if (ia != NULL){
		if (ia->len > index){
			if (val != NULL){
				ia->data[index] = *val;
				return INTARR_OK;		
			}
		}
		return INTARR_BADINDEX;
	} else {
		return INTARR_BADARRAY;	
	}
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){
	intarr_t *dup = malloc(sizeof(intarr_t));
	if (dup == NULL){
		return NULL;	
	}
	dup->len = ia->len;
	dup->data=malloc(sizeof(int)*dup->len);
	memcpy(dup->data, ia->data, ia->len*sizeof(int));
  return dup;
}
