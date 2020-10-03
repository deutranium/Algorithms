# Exponential Search

- Exponential search allows for searching through a sorted, unbounded list for a specified input value.
- Time Complexity:
  - Worst Case Complexity:_O_(log _i_)
  - Best Case Complexity:_O_(1)
  - Average Case Complexity:_O_(log _i_)
- Worst Case Space Complexity:_O_(1)
- Exponential Search will run in _O_(log _i_) time, where _i_ is the index of the element being searched for in the list, whereas binary search would run in _O_(log _n_) time, where _n_ is the number of elements in the list.
- Works only on sorted lists.

### Logic

1.  Find range where element is present
2.  Do Binary Search in above found range.
3.  Pseudo Code:

           function exponentialSearch(arr, x, lo, hi):
        	if arr[hi] >= x:
        		return(binarySearch(arr, x, lo, hi + 1))
        	else:
        		return(exponentialSearch(arr, x, hi, hi * 2))

        	function binarySearch(arr, x, lo, hi):
        		index = (lo + hi)/2
        		if x = arr[index]
        			return index
        		else if x > arr[index]:
        			return binarySearch(arr, x, index, hi)
        		else:
        			return binarySearch(arr, x, 0, index)

### Implementations

- [Python](exponentialSearch.py)
- [C++](exponentialSearch.cpp)

### Instruction for Running code:

- Python

```
python3 exponentialSearch.py
```

- C++

For Windows

```
g++ exponentialSearch.cpp -o exponentialSearch.exe
exponentialSearch.exe
```

For Linux/ Mac

```
g++ exponentialSearch.cpp -o exponentialSearch.out
./exponentialSearch.out
```
