#include <stdio.h>
#include <math.h> 

int main()
{
   double num;
   scanf( "%le", &num);

   int low = floor(num);
   int high = ceil(num);
   int close = round(num);

   printf("%d %d %d\n", low, close, high);
   return 0;
}
