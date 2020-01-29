#include <stdio.h>
#include <math.h> 

int main(){
  int w, l, h;
  scanf("%d %d %d", &w, &l, &h);
  for (int i = 0; i < w; i++){
    printf("#");
  }
  printf("\n");
  if (l > 1){
    for (int f = 0; f < (l-2); f++){
      printf("#");
      int a = 0;
      while (a < (w-2)){
        printf(".");
        a++;
      }
      printf("#\n");
    }
  }
  for (int i = 0; i < w; i++){
    printf("#");
  }
  printf("\n");
}