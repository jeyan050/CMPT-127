#include <stdio.h>

int main (){
	char ch;
	unsigned int charcount = 0;
	unsigned int wordcount = 0;
	unsigned int linecount = 0;
	
	while((ch = getchar()) != EOF){
		if ('z'<= ch && ch >= 'a'||'Z'<= ch && ch >= 'A'||ch == '\''){
			charcount+= 1;	
		} else if (ch == ' '||ch == '\n'){
			wordcount+= 1;
			if (ch == '\n'){
				linecount+= 1;	
			}
		}
	}
	printf( "%lu %lu %lu\n", charcount, wordcount, linecount ); 
	return 0; 	
}