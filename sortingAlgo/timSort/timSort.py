RUN = 32

def insertion_sort(arr, left, right):
    # Sort a small portion of the array using insertion sort
    for i in range(left + 1, right + 1):
        temp = arr[i]
        j = i - 1
        while j >= left and arr[j] > temp:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = temp


def merge(arr, l, m, r):
    # Merge function for merging two sorted halves
    left = arr[l:m + 1]
    right = arr[m + 1:r + 1]

    i = j = 0
    k = l

    # Merge the two subarrays
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # Copy remaining elements, if any
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1


def tim_sort(arr):
    n = len(arr)

    # Sort individual subarrays of size RUN
    for i in range(0, n, RUN):
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1)))

    size = RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = left + size - 1
            right = min((left + 2 * size - 1), (n - 1))
            if mid < right:
                merge(arr, left, mid, right)
        size *= 2


def print_array(arr):
    print(" ".join(map(str, arr)))


def main():
    arr = [5, 21, 7, 23, 19]
    print("Given Array is")
    print_array(arr)

    tim_sort(arr)

    print("After Sorting Array is")
    print_array(arr)


if __name__ == "__main__":
    main()
