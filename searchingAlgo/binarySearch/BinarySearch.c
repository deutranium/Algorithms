int BinarySearch(int Arr[], int i, int f){

}

int main(){

	Arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 




	start = 0;  //INITIALISE
	end = ;   // SIZE OF ARRAY
	mid = (start + end)/2; // INITIALISE 
	ans = -1;  // IF ELEMENT IS NOT FOUND -1 WOULD BE PRINTED
	while( start > end ){

		if( Arr[mid] == X){
			ans = mid+1;
			break;
		}
		if(Arr[mid] > X)
			end = mid-1;
		else
			start = mid +1;
	}

	printf("%d", ans)
	return 0;
}