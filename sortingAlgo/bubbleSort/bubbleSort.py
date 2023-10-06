def bubbleSort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False  # Flag to track swaps in a pass.

        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:  # If elements are in the wrong order, swap them.
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True 

        if not swapped:  # If no swaps occurred in this pass, the list is already sorted.
            break

    return arr

arr = [1, 63, 103, 3, 8, 74, 76, 37, 71, 66]
sorted_arr = bubbleSort(arr)
print(sorted_arr)
