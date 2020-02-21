#include <stdio.h>
#include <string.h>

int main(){
	int greatestNum = 0;
	int tableNums[80] = {0};
	int place = 0;
	int level = 0;
	int num = 0;

	while (scanf("%d", &num) != EOF){
		tableNums[place] = num;
		place++;
		if (num > greatestNum){
			greatestNum = num;		
		}
	}
	for (int x = 0; x < greatestNum; x++){
		level = greatestNum - x;
		for (int a = 0; a < place; a++){
			if (tableNums[a] < level){
				printf(" ");
			} else if (tableNums[a] >= level){
				printf("#");			
			}		
		}
		printf("\n");
	}
}

