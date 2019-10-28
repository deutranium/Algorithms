#include<stdio.h>
 
//The below code is an algorithm implementing Binary search
//	It uses a while loop and has a time complexity of 
//	O(N) = log(N)
//	Θ(N) = log(N)
//	Ω(N) = 1 ( constant )
		

int main(){

	int start, end, mid, ans;

	int Arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int X = 0 ;


	start = 0;  //INITIALISE
	end = 10 ;   // SIZE OF ARRAY
	ans = -1;  // IF ELEMENT IS NOT FOUND -1 WOULD BE PRINTED

	while( start <= end ){

		mid = (start + end)/2; // INITIALISE 


		if( Arr[mid] == X){
			ans = mid+1;
			break;
		}

		else if(Arr[mid] > X)
			end = mid-1;

		else
			start = mid +1;


	}

	printf("%d\n", ans);
	return 0;
}
