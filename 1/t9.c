#include <stdio.h>
#include <math.h> 

int main(){
  int w, l, h;
  scanf("%d %d %d", &w, &l, &h);

  // TOP AND BODY
  int dx = w/2;
  int dz = h;
  
  // FIRST # and SPACES
  for (int level = h-1; level >= 0; level--){
    int m = dx * (level);
    int x = round(m / dz);
    for (int a = x; a > 0; a--){
      printf(" ");      
    }
    printf("#");

    int j = level;

    int left = floor( j * (w/(2.0*h)) );
    int right = ceil( (w-1) - (j *(w/(2.0*h))) ); 
    int differ = right - left; 

    if (level == 0 || level == h-1){
      for (int hash = 0; hash < differ; hash++){
        printf("#");
      }
      printf("\n");
    } else {
      for (int dot = 1; dot < differ; dot++){
        printf(".");
      }
      printf("#\n");
    } 
    j--;                
  }
}
