#include <stdio.h>
#include <math.h> 

int main()
{
	int a = 1;
	while (a == 1){
		double num;
		num = 0;
		int input = scanf( "%le", &num);
		if (input != EOF){		
			int low = floor(num);
      			int high = ceil(num);
      			int close = round(num);
      		printf("%d %d %d\n", low, close, high);
		} else {
			break;
		}
	}
	printf("Done.\n");
}
