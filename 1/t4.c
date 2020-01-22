#include <stdio.h>
#include <math.h> 

int main()
{
   double num;
   num = 0;
   scanf( "%le", &num);
   if (num != 0) 
      {
      int low = floor(num);
      int high = ceil(num);
      int close = round(num);
      printf("%d %d %d\n", low, close, high);
      return 0;
   } else {
      int error = num;
      printf("scanf error: (%d)\n", error);
   }
}

