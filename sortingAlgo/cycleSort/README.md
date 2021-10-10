# Cycle Sort
Cycle sort is a comparison sorting algorithm which forces array to be factored into the number of cycles where each of them can be rotated to produce a sorted array. It is theoretically optimal in the sense that it reduces the number of writes to the original array.

## Algorithm
Consider an array of n distinct elements. An element a is given, index of a can be calculated by counting the number of elements that are smaller than a.

* If the element is found to be at its correct position, simply leave it as it is.
* Otherwise, find the correct position of a by counting the total number of elements that are less than a. where it must be present in the sorted array. The other element b which is replaced is to be moved to its correct position. This process continues until we got an element at the original position of a.
* The illustrated process constitutes a cycle. Repeating this cycle for each element of the list. The resulting list will be sorted.

## Pseudo-code
```

Begin

 for start := 0 to n – 2 do
    key := array[start]
    location := start
    for i := start + 1 to n-1 do
      if array[i] < key then
         location:=location +1
    done

    if location = start then
        ignore lower part, go for next iteration
    while key = array[location] do
        location := location +1
    done

    if location ≠ start then
        swap array[location] with key
    while location ≠ start do
        location := start
        for i := start + 1 to n-1 do
               if array[i] < key then
                    location:=location +1
        done

        while key = array[location]
               location := location +1
        if key ≠ array[location]
               swap array[location] and key
  done
 done
End
```

## Complexity
-   Worst case time complexity:  `O(n^2)`
-   Average case time complexity:  `O(n^2)`
-   Best case time complexity:  `O(n^2)`
-   Space complexity:  `O(n)` Total, `O(1)` Auxiliary.

## Application
* This sorting algorithm is best suited for situations where memory write or swap operations are costly.

##  Instruction for Running code:
 - C
     ```
     gcc cycleSort.c
     ./a.out
     ```
 - Cpp

     ````
     g++ cycleSort.cpp
     ./a.out
     ````
- Java

    ```
    javac cycleSort.java
    java cycleSort.class
    ```
- Python
    ```
    python3 cycleSort.py
    ```
