# Selection Sort
Selection sort is an algorithm that separates an array into two subsections: a sorted section, and an unsorted section. The array is sorted by moving the lowest value element to the beginning of the unsorted section. It can also be adjusted to sort in reverse order.
```
selection sort(array)
  for i <- 0 to indexOfLastElement:
    k = i
    for j <- i + 1 to indexOfLastElement:
      if (array[j] < array[k])
        k = j    
    swap array[k] and array[i]
```

# Time Complexities:
- Worst Case: O(n<sup>2</sup>)
- Best Case: O(n)
