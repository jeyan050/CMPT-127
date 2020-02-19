#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	char *string = argv[1];
 	char *compare = argv[2];
	char *result;

	result = strstr(string, compare);
	if (result != NULL){
		printf("true\n");
	} else {
		printf("false\n"); 	
	}  
}
