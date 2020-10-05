#include <stdio.h>

// Function to find minimum of two given inputs
int min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

// A recursive binary search function. It returns location of x in given array a[l..r] is  present, otherwise -1
int binarySearch(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (a[mid] == x)
			return mid;

		// If element is smaller than mid, then it can only be present in left subarray
		if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(a, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

// Returns position of first occurrence of x in array
int exponentialSearch(int a[], int n, int x)
{
	// If x is present at firt location itself
	if (a[0] == x)
		return 0;

	// Find range for binary search by
	// repeated doubling
	int i = 1;
	while (i < n && a[i] <= x)
		i = i << 1;

	// Call binary search for the found range.
	return binarySearch(a, i / 2, min(i, n), x);
}

// Driver code
int main()
{
	int arr[] = {2, 5, 6, 7, 9, 15, 23, 24, 89};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 15;
	int result = exponentialSearch(arr, n, x);
	if (result != -1)
	{
		printf("Element found at index: %d\n", result);
	}
	else
	{
		printf("Element does not exist in given array\n");
	}
}
