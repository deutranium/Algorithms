# Quick Sort Algorithm

## overview
Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. A large array is partitioned into two arrays one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.

Quicksort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. This algorithm is quite efficient for large-sized data sets as its average and worst-case complexity are O(nLogn) and image.png(n2), respectively.

## Run 
In order to run the programs.
- First traverse to the directory ALGORITHMS-1/sortingAlgo/quickSort
- Then run the following commands in your terminal/cmd/powershell,

### For python file
```
python quickSort.py
```

### For javascript file
```
node quickSort.js
```