int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int sum1 = 0;
  int sum2 = 0; 
  int remain1 = 0;
  int remain2 = 0;

  for (int i = 0; i < len; i++){
    sum1+= arr1[i];
    sum2+= arr2[i];
    if (i != len-1){
      remain1 += arr1[i] % arr1[i+1];
    } else {
      remain1 += arr1[i] % arr1[0];
    }
    if (i != len-1){
      remain2 += arr2[i] % arr2[i+1];
    } else {
      remain2 += arr2[i] % arr2[0];
    }
  }

  if (remain1 == remain2 && sum1 == sum2){
    return 1;
  } else {
    return 0;
  }
}