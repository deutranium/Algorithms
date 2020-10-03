
﻿##  Bucket Sort
Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called **buckets**. The elements inside each **bucket** are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.

The process of bucket sort can be understood as **a scatter-gather** approach. The elements are first scattered into buckets then the elements of buckets are sorted. Finally, the elements are gathered in order.

    bucketSort()
	  create N buckets each of which can hold a range of values
	  for all the buckets
	    initialize each bucket with 0 values
	  for all the buckets
	    put elements into buckets matching the range
	  for all the buckets 
	    sort elements in each bucket
	  gather elements from each bucket
	end bucketSort

## Complexity
Shell sort is an unstable sorting algorithm because this algorithm does not examine the elements lying in between the intervals.
### Time Complexities:
* #### Worst Case Complexity: O(n<sup>2</sup>)
	When there are elements of close range in the array, they are likely to be placed in the same bucket. This may result in some buckets having more number of elements than others.  
It makes the complexity depend on the sorting algorithm used to sort the elements of the bucket.  
The complexity becomes even worse when the elements are in reverse order.
* #### Best Case Complexities: O(n+k)
	It occurs when the elements are uniformly distributed in the buckets with a nearly equal number of elements in each bucket.  
The complexity becomes even better if the elements inside the buckets are already sorted.
* #### Average Case Complexity: O(n)
	It occurs when the elements are distributed randomly in the array. Even if the elements are not distributed uniformly, bucket sort runs in linear time.

###  Bucket Sort Applications:
Bucket sort is used when
1. Input is uniformly distributed over a range.
2. There are floating point values.

###  Instruction for Running code:
 - C

     gcc BucketSort.c <br>
     ./a.out

 - Cpp
   

     g++ BucketSort.cpp<br>
     ./a.out

- Java
	

    javac BucketSort.java<br>
    java BucketSort.class

- Python

    python3 BucketSort\.py

  
