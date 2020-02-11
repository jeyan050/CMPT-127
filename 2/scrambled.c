int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
  int totalSame = 0;
  for (int i = 0; i < len; i++){
    for (int a = 0; a < len; a++){
      if (arr1[i]==arr2[a]){
        totalSame++;
	break;
      }
    }
  }
  if (totalSame == len){
    return 1;
  } else {
    return 0;
  }
}

