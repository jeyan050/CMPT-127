int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int totalSame1 = 0;
  int totalSame2 = 0;
  for (int i = 0; i < len; i++){
    for (int a = 0; a < len; a++){
      if (arr1[i]==arr2[a]){
        totalSame1++;
	break;
      }
    }
  }
  for (int i = 0; i < len; i++){
    for (int a = 0; a < len; a++){
      if (arr1[i]==arr2[a]){
        totalSame2++;
	break;
      }
    }
  }
  if (totalSame1 == totalSame2){
    return 1;
  } else {
    return 0;
  }
}