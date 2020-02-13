int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int productArr1 = 1;
  int productArr2 = 1;

  int sumArr1 = 0;
  int sumArr2 = 0;

  for (int i = 0; i < len; i++){

    sumArr1 += arr1[i];
    sumArr2 += arr2[i];

    productArr1 *= arr1[i];
    productArr2 *= arr2[i];
  }

  if (productArr1 == productArr2 && sumArr1 == sumArr2){
    return 1;
  } else {
    return 0;
  }
}
