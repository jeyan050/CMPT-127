#include <stdio.h>

int main (){
	char ch;
	unsigned int charcount = 0;
	unsigned int wordcount = 0;
	unsigned int linecount = 0;
	ch = getchar();

	while(ch != EOF){
		charcount += 1;
		if ('z'<= ch >= 'a'||'Z'<= ch >= 'A'||ch == '\''){
    			wordcount=wordcount+1;
		} else if (ch == '\n'){
			linecount+= 1;		
		}
	}
	printf( "%lu %lu %lu\n", charcount, wordcount, linecount ); 
	return 0; 	
}
