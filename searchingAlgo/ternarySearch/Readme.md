## Ternary Search
Ternary search is a divide-and-conquer search algorithm. It is mandatory for the array (in which you will search for an element) to be sorted before we begin the search. In this search, after each iteration it neglects ⅓ part of the array and repeats the same operations on the remaining ⅔.
### Algorithm

The steps involved in this algorithm are:  
(The list must be in sorted order)

-   **Step 1**: Divide the search space (initially, the list) in three parts (with two mid-points:  `mid1`  and  `mid2`)
-   **Step 2**: The target element is compared with the edge elements that is elements at location  `mid1`,  `mid2`  and the end of the search space. If element matches, go to step 3 else predict in which section the target element lies. The search space is reduced to  `1/3`rd. If the element is not in the list, go to step 4 or to step 1.
-   **Step 3**: Element found. Return index and exit.
-   **Step 4**: Element not found. Exit.
### Recursive algorithm

	def ternary_search(f, left, right, absolute_precision) -> float:
	    """Left and right are the current bounds;
	 the maximum is between them.
	 """
	    if abs(right - left) < absolute_precision:
	        return (left + right) / 2

	    left_third = (2*left + right) / 3
	    right_third = (left + 2*right) / 3

	    if f(left_third) < f(right_third):
	        return ternary_search(f, left_third, right, absolute_precision)
	    else:
	        return ternary_search(f, left, right_third, absolute_precision)
### Iterative Algorithm

	def ternary_search(f, left, right, absolute_precision) -> float:
	    """Find maximum of unimodal function f() within [left, right]
	 To find the minimum, reverse the if/else statement or reverse the comparison.
	 """
	    while abs(right - left) >= absolute_precision:
	        left_third = left + (right - left) / 3
	        right_third = right - (right - left) / 3

	        if f(left_third) < f(right_third):
	            left = left_third
	        else:
	            right = right_third

	     # Left and right are the current bounds; the maximum is between them
	     return (left + right) / 2

### Complexity
-   Worst case time complexity:  `O(log N)`
-   Average case time complexity:  `O(log N)`
-   Best case time complexity:  `O(1)`
-   Space complexity:  `O(1)`
### Applications

-   This concept is used in unimodal functions to determine the maximum or minimum value of that function. Unimodal functions are functions that, have a single highest value.
-   Can be used to search for where the derivative is zero in Newton's method as an optimization.


