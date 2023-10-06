def heapify(arr, n, i):
    """
    Helper function to transform a subarray into a heap.
    
    :param arr: The array to be sorted.
    :param n: The size of the array.
    :param i: Index of the root of the subtree.
    """
    largest = i  # Initialize the largest element as the root
    left = 2 * i + 1
    right = 2 * i + 2

    # Check if the left child exists and is greater than the root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if the right child exists and is greater than the root
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If the largest element is not the root, swap them
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        # Recursively call heapify on the subtree
        heapify(arr, n, largest)

def heapSort(arr):
    """
    Implementation of the Heapsort algorithm.
    
    :param arr: The array to be sorted.
    """
    n = len(arr)

    # Build a heap (heapify) from the bottom up
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements from the heap one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap the root with the last element
        heapify(arr, i, 0)  # Call heapify on the reduced heap

# Example usage
arr = [12, 11, 13, 5, 6, 7]
print("Array before sorting:")
print(arr)
heapSort(arr)
print("Array after sorting:")
print(arr)
