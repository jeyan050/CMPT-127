int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int product1 = 0;
  int product2 = 0; 
  int remain1 = 0;
  int remain2 = 0;

  for (int i = 0; i < len; i++){
    product1*= arr1[i];
    product2*= arr2[i];
    
    product1/= arr2[i];
    product2/= arr1[i];
  }

  if (product2 == 0 && product1 == 0){
    return 1;
  } else {
    return 0;
  }
}