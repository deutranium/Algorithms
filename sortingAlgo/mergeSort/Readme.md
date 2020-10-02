**MERGE SORT**

Time Complexity: **O(nlogn)**  n: size of the array </br>
Space Complexity : **O(n)**   n: size of the array </br>

 **ALGORITHM**</br>
 
        Merge_sort (arr, left, right)
        
           if left < right                                                    
             THEN mid <= left+(right-left)/2
                merge_sort(arr,left,mid)
                merge_sort(arr, mid+1, right)
                merge(arr, l,r);
           else 
                return
          endif 

Merge Sort is based on **Divide and Conquer**, which means we divide a problem to smaller subproblems and try to solve those  small subproblem individually to come up with a solution.</br>

We can say that an array of single element is always sorted.Merge sort is based on this property only. We divide the whole array in smaller parts and sort them.Then we merge this sorted arrays to recover back our original array </br>
 
                                                                                                                                                     
                                                                          3 5 4 1 2              UNSORTED ARRAY
                                                                              |
                                                                          ----------
                                                                          |         |
                                                                         3 5      4 1 2         DIVIDED IN TWO SMALLER ARRAYS
                                                                          |         |
                                                                        -----   ------------    FURTHER DIVIDED
                                                                        |   |   |          |  
                                                                        3   5   4         1 2     3,4,5 ARE SORTED IN ITSELF
                                                                        \   /   |          |
                                                                         3 5    |         ----     MERGING SORTED ARRAYS CONTAINING 3 AND 5 AND FURTHER DIVIDING 1 2
                                                                          |     |         |   |
                                                                          |     |         1   2    1, 2 SORTED IN ITSELF
                                                                          |      \        \   /
                                                                          |       \        1 2     MERGED TWO SORTED ARRAYS
                                                                           \       \       /
                                                                            \       \     /
                                                                             \       \   /
                                                                              \      1 2 4         MERGED TWO SORTED ARRAYS ([4] , [1,2])
                                                                               \       /
                                                                                \     /
                                                                               1 2 3 4 5            MERGED TWO SORTED ARRAYS ([1,2,4], [3,5])
