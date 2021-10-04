package main

import "fmt"

func cocktailSort(arr []int) {
	n := len(arr)
	for { // forever loop, as long as there are changes in the array
		swapped := false
		// reset the 'swapped' flag
		for i := 0; i < n-1; i++ {
			if arr[i] > arr[i+1] {
				arr[i], arr[i+1] = arr[i+1], arr[i]
				swapped = true
			}
		}
		// if they are no changes in the entire iteration,
		// this means that the algorithm has ended
		if !swapped {
			break
		}
	}
}

func main() {

	// user input
	fmt.Printf("Enter number of elements in array: ")
	var n int
	fmt.Scanf("%d", &n)

	fmt.Printf("Enter the array: ")
	var arr []int
	for i := 0; i < n; i++ {
		var k int
		fmt.Scanf("%d", &k)
		arr = append(arr, k)
	}

	cocktailSort(arr)

	fmt.Printf("Sorted array: %v\n", arr)
}
