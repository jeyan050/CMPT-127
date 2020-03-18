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

	if (ia==NULL){
		return INTARR_BADARRAY;
	}
	//check if index is out of range, if so return badarray
	if(index < 0 || index > ((ia->len)-1)){
		return INTARR_BADINDEX;
		
	}
	//index should be in range now
	
	ia->data[index]= val;
	return INTARR_OK;

}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* val ){
	if (ia == NULL){
    return INTARR_BADARRAY;
  } else if (index<ia->len && ia != NULL){
    *val = ia->data[index];
    return INTARR_OK;
  } else {
    return INTARR_BADINDEX;
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


/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
  if(ia == NULL){
		return INTARR_BADARRAY;	
	}
	int min, switchpos, tmp;
	for (int i = 0; i < ia->len; i++){
		min = ia->data[i];
		for (int a = i; a < ia->len; a++){
			if (ia->data[a] < min){
				min = ia->data[a];	
				switchpos = a;	
			}		
		}
		tmp = ia->data[i];
		ia->data[i] = min;
		ia->data[switchpos] = tmp;
	}
	return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  if (ia == NULL){
		return INTARR_BADARRAY;	
	}
	for (int a = 0; a < ia->len; a++){
		if (ia->data[a] == target && i != NULL){
			*i = a;
			return INTARR_OK;
		}
	}
	return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  if (ia == NULL){
		return INTARR_BADARRAY;	
	}
	intarr_resize(ia, ia->len+1);
	ia->data[ia->len+1] = val;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if (ia->len == 0 || ia->data[0] == 0){
		return INTARR_BADINDEX;	
	}
	if (i != NULL){
		*i = ia->data[ia->len-1];
		ia->data[ia->len-1] = 0;
		ia->len = ia->len-1;
		return INTARR_OK;
	}
	return INTARR_BADARRAY;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. 
// If newlen is greater than the original array length, the values 
// of the new integers will be undefined 
// (see https://en.cppreference.com/w/c/memory/realloc). 
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  if (ia == NULL)
		return INTARR_BADARRAY;
	int origLen;
	origLen = ia->len;
	if (newlen >= 0){
		int *newData = realloc(ia->data,sizeof(int)*newlen);
		ia->len = newlen;
		ia->data = newData;
		if(newData){
			if(newlen>origLen){
				for(int i = origLen; i < newlen; i++){
					ia->data[i] = 0;
				}			
			}		
		}
		return INTARR_OK;
	}
	return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ){
  if (ia == NULL || first > ia->len || last > ia->len || last < first){
		return NULL;	
	}
	int copyPos = 0;
  int newLen;
	intarr_t *copy = malloc(sizeof(intarr_t));
	if (copy != NULL && first <= last){
		newLen = last-first+1;
		copy->len = newLen;
		copy->data = malloc(sizeof(int)*newLen);
		for (int i = first; i <= last; i++){
			copy->data[copyPos] = ia->data[i];
			copyPos++;
		}
		return copy;
	}
	return NULL;
}
