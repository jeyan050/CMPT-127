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
  for (int level = h; level > 0; level--){
    int x = dx * (level) / dz;
    for (int a = x; a > 1; a--){
      printf(" ");      
    }
    printf("#");   
  // DOTS AND LEFTOVER HASHES
    int left = floor( j * (w/(2.0*h)) ); // 0 5
    int right = ceil( (w-1) - (j *(w/(2.0*h))) ); // 11 6
    int differ = right - left; // 11 1

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