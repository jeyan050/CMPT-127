int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int a = 0;
  int n = 0;
  int sameNums = 0;
  while (n < len){
    if (arr1[n] == arr2[a]){
      sameNums++;
      n++;
    } else {
      a++;
    }
  }
  if (sameNums == len){
    return 1;
  } else {
    return 0;
  }
}