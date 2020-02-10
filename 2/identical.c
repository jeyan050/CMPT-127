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


