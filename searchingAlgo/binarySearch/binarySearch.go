package main

import "fmt"

// recursive implementation of binary search
func binarySearch(arr []int, x, l, r int) (int, bool) {

	// boundary condition
	if l > r {
		return -1, false
	}

	if mid := (r-l)/2 + l; arr[mid] == x { // when found, return the index
		return mid, true
	} else if arr[mid] < x {	// if query element is greater than the middle, search the right half
		return binarySearch(arr, x, mid+1, r)
	} else {					// if query element is less than the middle, search the left half
		return binarySearch(arr, x, l, mid-1)
	}
}

func main() {
	fmt.Printf("Enter number of elements in array: ")
	var n, x int
	fmt.Scanf("%d", &n)

	fmt.Printf("Enter the sorted array: ")
	var arr []int
	for i := 0; i < n; i++ {
		var k int
		fmt.Scanf("%d", &k)
		arr = append(arr, k)
	}

	fmt.Printf("Enter the element to be searched: ")
	fmt.Scanf("%d", &x)

	idx, found := binarySearch(arr, x, 0, n-1)

	if !found {
		fmt.Printf("Element %d not found.\n", x)
	} else {
		fmt.Printf("Element %d found at position %d.\n", x, idx)
	}
}
