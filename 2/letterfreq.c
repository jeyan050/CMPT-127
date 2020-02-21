#include <stdio.h>
#include <string.h>

int main()
{
	int inputletter;

	int lowerValue;
	int upperValue;

	int sum = 0;
	int num;
	float freq;
	char letter;
	
	char alp [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int tableValues[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	while ((inputletter = getchar()) != EOF)
	{
		for (int i = 0; i < 26; i++)
		{
			lowerValue = 65+i;
			upperValue = 97+i;
			if (inputletter == lowerValue || inputletter == upperValue)
			{
				sum++;
				tableValues[i]+= 1;
			}		
		}
	}
	for (int j = 0; j < 26; j++)
	{
		num = tableValues[j];
		freq = num / (float)sum;
		letter = alp[j];
		if (freq != 0)
		{
			printf( "%c %.4f\n", letter, freq); 
		}
	} 
}
