
# Insertion Sort

 - Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
 - Time Complexity:
     - Worst Case Complexity:O(n2)
     - Best Case Complexity:O(1)
     - Average Case Complexity:O(n2)
	- Worst Case Space Complexity:O(1)

### Logic

 1. The first element in the array is assumed to be sorted. Take the second element and store it separately in `key`.Compare `key` with the first element. If the first element is greater than `key`, then key is placed in front of the first element.. 
 2. Now, the first two elements are sorted. Take the third element and compare it with the elements on the left of it. Placed it just behind the element smaller than it. If there is no element smaller than it, then place it at the beginning of the array.
 3. Similarly, place every unsorted element at its correct position.
 ### Pseudo Code:

	for j <- 2 to length [_A_]

	    do key <- A [_j_]

		  Insert A [j] into the sorted sequence A[1..j-1]

		i<-j- 1

	while i >0 and A[i]  >key
	
		do A[i+1]<-A[i]
	
		i <-i-1

		A[i + 1] <-key

###  Instruction for Running code:

  
- Cpp
  	g++ bubbleSort.cpp
	./a.out  
- Python
	python3 InsertionSort.py
