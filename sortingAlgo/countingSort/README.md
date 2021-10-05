# COUNTING SORT
The lower bound nlogn does not apply to algorithms that do not compare array
elements but use some other information. An example of such an algorithm is
counting sort that sorts an array in O(n) time assuming that every element in
the array is an integer between 0... c and c = O(n).
The algorithm creates a bookkeeping array, whose indices are elements of the
original array. The algorithm iterates through the original array and calculates
how many times each element appears in the array.
## Logic
For example, the array

1 3 6 9 9 3 5 9

corresponds to the following bookkeeping array:

1 0 2 0 1 1 0 0 3
1 2 3 4 5 6 7 8 9

For example, the value at position 3 in the bookkeeping array is 2, because
the element 3 appears 2 times in the original array.
Construction of the bookkeeping array takes O(n) time. After this, the sorted
array can be created in O(n) time because the number of occurrences of each
element can be retrieved from the bookkeeping array. Thus, the total time
complexity of counting sort is O(n).
Counting sort is a very efficient algorithm but it can only be used when the
constant c is small enough, so that the array elements can be used as indices in
the bookkeeping array.

## Time Complexity

### Best Case:
The best case time complexity occurs when all elements are of the same range that is when k is equal to 1.
In this case, counting the occurrence of each element in the input range takes constant time and then finding
the correct index value of each element in the sorted output array takes n time, thus the total time complexity reduces to O(1 + n) i.e O(n) which is linear.

N is the number of elements
K is the range of elements (K = largest element - smallest element)

### Worst Case:
Worst case time complexity is when the data is skewed that is the largest element is significantly large than other elements. This increases the range K.

As the time complexity of algorithm is O(n+k) then, for example, when k is of the order O(n^2), it makes the time complexity O(n+(n^2)), which essentially
reduces to O( n^2 ) and if k is of the order O(n^3), it makes the time complexity O(n+(n^3)), which essentially reduces to O( n^3 ).
Hence, in this case, the time complexity got worse making it O(k) for such larger values of k. And this is not the end. It can get even worse for further larger values of k.
Thus the worst case time complexity of counting sort occurs when the range k of the elements is significantly larger than the other elements.

## Space complexity

In the above algorithm we have used an auxiliary array C of size k, where k is the max element of the given array. Therefore the space complexity of Counting Sort algorithm is O(k).

Space Complexity : O(k)

Larger the range of elements in the given array, larger is the space complexity, hence space complexity of counting sort is bad if the range of integers are very large as the auxiliary array of that size has to be made.
