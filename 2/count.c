#include <stdio.h>



int main (){

	char ch;

	long unsigned int charcount = 0;

	long unsigned int wordcount = 0;

	long unsigned int linecount = 0;
	int word = 1;

	

	while((ch = getchar()) != EOF){

		charcount+= 1;
		if (ch>='a' && ch<='z'||ch>='A' && ch<='Z'||ch=='\''){
			if (word==1){
    				wordcount+=1;
    				word=0;
    			}	
		} else {
			word=1;
		}

		if (ch == '\n'){

			linecount+= 1;
			word=1;	

		}

	}

	printf( "%lu %lu %lu\n", charcount, wordcount, linecount ); 

	return 0; 	

}