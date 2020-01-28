#include <stdio.h>
#include <math.h> 

int main(){
	int a = 0;
  int i;
  double input;
  input = 0;
  while (a == 0) {
    double numHash = scanf("%le", &input);
    if (numHash != EOF){
      char hash = '#';
      for (i = 0; i < input; i++){
        printf("%c", hash);
      }
      printf("\n");
    } else {
      break;
    }
  }
}