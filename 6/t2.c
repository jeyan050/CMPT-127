#include <stdio.h>
#include "intarr.h"
#include <stdlib.h>
#include <string.h>


/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
	if (ia == NULL || ia->data == NULL || filename == NULL){
		return 1;	
	}
	
	FILE* f = fopen(filename, "w");
	fprintf(f, "[");
	for (int i = 0; i < ia->len; i++){
		fprintf(f, " %d", ia->data[i]);
		if (i != ia->len-1){
			fprintf(f, ",");		
		}
	}
	fprintf(f, "]");
	fclose(f);
	return 0;
}


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_json( const char* filename ){
	if (filename == NULL)
    {
        return NULL;
    }
    FILE * file;
    file = fopen (filename, "r+");
    if (file==NULL)
    {
        return NULL;
    }
    int count=0;
    char ch;
    int k,i=0;
    intarr_t *new=malloc(sizeof(intarr_t));
    
    while (!feof(file))    // count number of elements
    {
        ch = getc(file);
        if (ch == ','){
            count ++;
        }
    }
    fseek(file,0,SEEK_SET);
    //int array[count+1];
    //Consider if count=0;
    if (count==0)
    {
        new->len = 0;
        new->data = NULL;
        return new;
    }
    new->len=count+1;
    new->data=malloc(sizeof(int)*new->len);
    
    while(i<new->len)
    {
        while (fscanf(file, "%d",&k)!=1)
        {
            fseek(file, 1, SEEK_CUR);
            
        }
        //printf("!!%d\n",k);
        new->data[i]=k;
        //printf("%d!!\n",new->data[i]);
        i++;
    }
    fseek(file,0,SEEK_END);
    fclose(file);
    
    return new;
}





