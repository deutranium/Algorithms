# Heap Sort
Heap sort is one of the sorting algorithms used to arrange a list of elements in order. Heapsort algorithm uses one of the tree concepts called Heap Tree. 
In this sorting algorithm, we use Max Heap to arrange list of elements in Descending order and Min Heap to arrange list elements in Ascending order.
There are 2 variations of heap possible
### MIN HEAP
* Here the value of parent is always less than the value of its children
Hence root will be the minimum in the entire heap
### MAX HEAP
* Here the value of parent is always more than the value of its children
Hence root will be the maximum in the entire heap

## Algorithm
* Step 1 - Construct a Binary Tree with given list of Elements.
* Step 2 - Transform the Binary Tree into Max Heap.
* Step 3 - Delete the root element from Max Heap using Heapify method.
* Step 4 - Put the deleted element into the Sorted list.
* Step 5 - Repeat the same until Max Heap becomes empty.
* Step 6 - Display the sorted list.

## Pseudo-code
```
heapify(arr , i)
	leftChild = arr [2*0 + 1];
	rightChild = arr [2*0 + 2];
    	maxIndex = max( arr[i], leftChild, rightChild)
    	if(i != maxIndex)
          		swap(arr[i], arr[maxIndex])
  ```
  ```
  buildMaxHeap(arr)
	for(int i = n / 2 - 1; i >= 0; i--)
     		 heapify(arr, i);
```

## Complexity

-   Worst case time complexity:  `O(n log n)`
-   Average case time complexity:  `O(n log n)`
-   Best case time complexity:  `O(n log n)`
-   Space complexity:  `O(1)`

## Applications of Heap Sort 
* K sorted array
* K largest or smallest elements in an array 

###  Instruction for Running code:
 - C
     ```
     gcc heapSort.c
     ./a.out
     ```
 - Cpp

     ````
     g++ heapSort.cpp
     ./a.out
     ````
- Java

    ```
    javac heapSort.java
    java heapSort.class
    ```
- Python
    ```
    python3 heapSort.py
    ```
