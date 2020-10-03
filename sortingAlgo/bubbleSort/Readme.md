## Bubble Sort
Bubble sort is an algorithm that compares the adjacent elements and swaps their positions 
if they are not in the intended order. The order can be ascending or descending.

    bubbleSort(array)
	  swapped <- false
	  for i <- 1 to indexOfLastUnsortedElement-1
	    if leftElement > rightElement
	      swap leftElement and rightElement
	      swapped <- true
	end bubbleSort

## Complexity
Bubble Sort is one of the simplest sorting algorithms. Two loops are implemented in the algorithm.
### Time Complexities:
* #### Worst Case Complexity: O(n<sup>2</sup>)
	If we want to sort in ascending order and the array is in descending order then, the worst case occurs.
* #### Best Case Complexities: O(n)
	If the array is already sorted, then there is no need for sorting.
* #### Average Case Complexity: O(n<sup>2</sup>)
	It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

### Space Complexity:
Space Complexity is **O(2)** because the variable swapped adds to the space complexity.
### Bubble Sort Applications:
It is used in the following cases where
1. the complexity of the code does not matter.
2. a short code is preffered.
