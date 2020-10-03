#include <bits/stdc++.h> 
using namespace std; 

// A iterative binary search function. It returns location of x in given array arr[l..r] if present, otherwise -1 

int binarySearch(int arr[], int l, int r, int x) 
{ 
	while (l <= r) { 
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x) 
			return mid; 

		if (arr[mid] < x) 
			l = mid + 1; 

		else
			r = mid - 1; 
	} 

	return -1; 
} 

int main() 
{ 
  int n ; 
  cin>>n ;
  int arr[n] ; 
  for(int i=0; i<n; i++){
    cin>>arr[i] ;
  }    
	int num ; 
  cin>>num ; 
	int result = binarySearch(arr, 0, n - 1, num); 
	cout<<result<<endl;
	return 0; 
} 
