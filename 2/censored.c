#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//printf("CHECK");

int main( int argc, char *argv[]){
	char line[1000];
	char *compare;
	int start = 0;
	int lineLen, compareLen, wordLen;
	int spots = 0;

	while(fgets(line, 100, stdin) != NULL){
		lineLen = strlen(line);
		start = 0;
		for (int numCen = 1; numCen <= argc-1; numCen++){
			if ((compare = strstr(line, argv[numCen])) != NULL){
				spots = 0;
				compareLen = strlen(compare);
				wordLen = strlen(argv[numCen]);
				for (int i = start; i < lineLen-compareLen;i++){
					printf("%c", line[i]);
					spots++;				
				}			
				printf("CENSORED");
				start += spots + wordLen;
			}
		}
		if (start < lineLen){
			for (int j = start; j < lineLen; j++){
			printf("%c",line[j]);
		}
	}
	}
}
