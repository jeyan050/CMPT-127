#include <stdio.h>
#include "intarr.h"
#include <stdlib.h>
#include <string.h>

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
	if (ia == NULL || ia->data == NULL){
		return 1;
	}
	
	FILE* f = fopen(filename, "w");
	if (f == NULL){
		return 1;	
	}
	if (fwrite(ia->data, sizeof(int), ia->len, f) == ia->len){
		fclose(f);
		return 0;
	} else {
		fclose(f);
		return 1;
	}
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_binary( const char* filename ){
		 if (filename==NULL)
    {
        return NULL;
    }
    FILE *file = fopen( filename ,"r");
    if (file==NULL)
    {
        return NULL;
    }
    fseek(file,0,SEEK_END);
    int size = ftell(file)/sizeof(int);

    fseek(file,0,SEEK_SET);

    intarr_t *arr=malloc(sizeof(intarr_t));
    arr->len=size;

    arr->data=malloc(sizeof(int)*arr->len);

    int rlen=fread(arr->data, sizeof(int), size, file);
    if(rlen==arr->len)
    {
        fclose( file );
        return arr;
    }
    
    else{
        fclose( file );
        return NULL;
        
    }   
}
