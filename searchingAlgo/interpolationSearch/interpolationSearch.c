#include <stdio.h>

/* Interpolation Search: 
    Condition: 
    array or vector should be sorted of n uniformly distributed value
    * sorted : in a sequence of either increasing or decreasing
    * uniformly distributed : difference between every consecutive element must be same
    * consecutive element difference : arr[8]-arr[7] = arr[2]-arr[1] = .. so on
    
    terminolgy used: 
    arr : int arr 
    n : given element to be searched
    lo : starting index
    hi : ending index
    
    Logic used: 
    * recursion
*/
int interpolationSearch(int arr[], int lo, int hi, int x)
{
	int pos;
	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
	{
		pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
		
		if (arr[pos] == x)
			return pos;
		if (arr[pos] < x) //x is in right sub array as is closer to hi
			return interpolationSearch(arr, pos + 1, hi, x);
		if (arr[pos] > x) //x is in left sub array as is closer to lo
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

// Driver Code
int main()
{
	//test cases:
	/*  to print the index of the Element searched in the array 
	    starting from 0 and to print -1 if the element is not 
	    found.
	    
	    ** diff : |arr[n]-arr[n-1]|
	*/
	
	//test case 1 : all pos int with diff=1
	int arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int x = 17; // Element to be searched
	int res = interpolationSearch(arr1, 0, n - 1, x);
	printf("%d\n", res);
	
	//test case 2 : with negative numbers with diff=1
	int arr2[] = { -5,-4,-3,-2,-1,0,1,2,3,4,5,6,7};
	n = sizeof(arr2) / sizeof(arr2[0]);
	x = -2; // Element to be searched
	res = interpolationSearch(arr2, 0, n - 1, x);
	printf("%d\n", res);
	
	//test case 3 : diff=5
	int arr3[] = { -15,-10,-5,0,5,10};
	n = sizeof(arr3) / sizeof(arr3[0]);
	x = 5; // Element to be searched
	res = interpolationSearch(arr3, 0, n - 1, x);
	printf("%d\n", res);
	
	//test case 4 : element not found
	int arr4[] = { -15,-10,-5,0,5,10,15,20};
	n = sizeof(arr4) / sizeof(arr4[0]);
	x = -2; // Element to be searched
	res = interpolationSearch(arr4, 0, n - 1, x);
	printf("%d\n", res);
	
	//conditions check: 
	
	//test case 5 : unsorted
	// unsorted thus will provide inconsistent solution (may give correct or may not)
	int arr5[] = {1,7,-8, 23, 6};
	n = sizeof(arr5) / sizeof(arr5[0]);
	x = 6; // Element to be searched
	res = interpolationSearch(arr5, 0, n - 1, x);
	printf("%d\n", res);
	
	//test case 6 : variable difference
	// sorted not uniformly increasing or decreasing thus won't be able to find
	int arr6[] = {1,2,4,7,9,2};
	n = sizeof(arr6) / sizeof(arr6[0]);
	x = 7; // Element to be searched
	res = interpolationSearch(arr6, 0, n - 1, x);
	printf("%d\n", res);
	
	//test case 7 : diff=0 (same elements) 
	// sorted not uniformly increasing or decreasing thus will provide garbage or null value
	int arr7[] = {0,0,0,0,0,0,0,0,0,0,0};
	n = sizeof(arr7) / sizeof(arr7[0]);
	x = 0; // Element to be searched
	res = interpolationSearch(arr7, 0, n - 1, x);
	printf("%d\n", res);
	
	return 0;
}
