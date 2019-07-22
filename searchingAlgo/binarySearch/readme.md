## Binary Search

 - Only for sorted arrays: Yes
 - Time Complexity
 	- Worst Case: O(log n)
 	- Average: O(log n)
 	- Best Case: O(1)
 - Worst Case Space Complexity: O(1)

### Logic
1. Let the value to be searched for be `x`
2. For a sorted array(`arr`), find the middle index(`mid`), and compare the `arr[mid]` with `x`.
3. **If** `x` is equal to the middle value, return `mid`
4. **Else if** on the basis of comparison, `x` lies to the left of the middle value, repeat the steps starting from #2 for the first half of the array
5. **Else** `x` will lie in the second half of the array, and hence repeat the steps starting from #2 for the second half of the array


<sub>**Read this or your laptop *(or phone or whatever)* will burst:**<br>
I haven't considered duplicate elements to be present in the array(yet). If need to consider that too, then well... use some brains :grin: </sub>
