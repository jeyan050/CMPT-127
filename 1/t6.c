#include <stdio.h>
#include <math.h> 

int main(){
	int a = 1;
	double lowest = 100000;
	double highest = -100000;
	double total = 0;
	int amountNums = 0;
	while (a == 1){
		double num = 0;
		double input = scanf( "%le", &num);
		if (input != EOF){
			if (num < lowest){
				lowest = num;
			}
			if (num > highest){
				highest = num;
			}
			total = total + num;
			amountNums += 1;
		} else {
			break;
		}
	}
	float high = highest;
	float low = lowest;
	float mean = total/amountNums;
	printf("%.2f %.2f %.2f\n", low, high, mean);
}
