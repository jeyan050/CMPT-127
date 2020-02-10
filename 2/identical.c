int identical( int arr1[], int arr2[], unsigned int len ){
	int numSame = 0;

	if (len == 0){
		return 1;	
	}
	for (int i = 0; i < len; i++){
		if (arr1[i] == arr2[i]){
			numSame++;	
		} 
	}
	if (numSame != len){
		return 0;	
	} else {
		return 1;		
	}
}

