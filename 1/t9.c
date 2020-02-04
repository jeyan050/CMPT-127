#include <stdio.h>
#include <math.h> 

int main(){
  int w, l, h;
  scanf("%d %d %d", &w, &l, &h);

  // TOP AND BODY
  int dx = w/2;
  int dz = h;
  
  int j = h - 1;
  // FIRST # and SPACES
  for (int level = h; level > 0; level--){ // 4 3 2 1
    double m = dx * level;
    int x = ceil(m / dz);
    for (int a = x; a > 1; a--){
      printf(" ");      
    }
    printf("#");   
  // DOTS AND LEFTOVER HASHES
    int left = floor( j * (w/(2.0*h)) ); // 0 1/2 1 3/2   -- 0 0 1 1
    int right = ceil( (w-1) - (j *(w/(2.0*h))) ); // 3 3 2 2
    int differ = right - left; // 3 3 1 1

    if (level == 1 || level == h){
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