## Shell Sort
Shell sort is an algorithm that first sorts the elements far apart from each other and successively reduces the interval between the elements to be sorted. It is a generalized version of insertion sort.

In shell sort, elements at a specific interval are sorted. The interval between the elements is gradually decreased based on the sequence used. The performance of the shell sort depends on the type of sequence used for a given input array.

    shellSort(array, size)
	  for interval i <- size/2n down to 1
	    for each interval "i" in array
	        sort all the elements at interval "i"
	end shellSort
## Complexity
Shell sort is an unstable sorting algorithm because this algorithm does not examine the elements lying in between the intervals.
### Time Complexities:
* #### Worst Case Complexity: less than or equal to O(n<sup>2</sup>)
* #### Best Case Complexities: O(n*log n)
	When the array is already sorted, the total number of comparisons for each interval (or increment) is equal to the size of the array.
* #### Average Case Complexity: O(n*log n)
	It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

### Space Complexity:
The space complexity for shell sort is **O(1)**
### Shell Sort Applications:
Shell sort is used when
1. calling a stack is overhead.
2. recursion exceeds a limit.
3. Insertion sort does not perform well when the close elements are far apart. Shell sort helps in reducing the distance between the close elements. Thus, there will be less number of swappings to be performed.

###  Instruction for Running code:

- Python
    ```
    python3 ShellSort.py
    ```
