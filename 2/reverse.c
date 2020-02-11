void reverse( int arr[], unsigned int len ){	
	for (int i = 0; i < len/2 ; i++){
		int high = arr[len-1-i];
		int low = arr[i];
		arr[len-1-i] = low;
		arr[i] = high;
	}
}

