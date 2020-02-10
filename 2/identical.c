#include <stdio.h>

int identical( int arr1[], int arr2[], unsigned int len ){
	int intentical;
	
	for (int i = 0; i< len; i++){
		if (arr1[i] == arr2[i]){
			return 1;		
		} else {
			return 0;
		}
	}

}

int main( void )
{
   int arr1[3] = {10, 15, 20};
   int arr2[3] = {10, 20, 15};
 
   if( identical( arr1, arr2, 3 ) == 1 )
   { 
      printf( "arr1 and arr2 are identical\n" );
   }  else {
      printf( "arr1 and arr2 are NOT identical\n" );
   }
 
   return 0;
}

