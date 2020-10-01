# Factor thatthe gap should shrink by after each iteration
SHRINK_FACTOR = 10.0 / 13.0


def next_gap(currentGap):
    """
        Calculates the next value to be used as the gap
    """
    gap = int(currentGap * SHRINK_FACTOR)
    if gap < 1:
        return 1
    else:
        return gap


def comb_sort(arr):
    """
        Sorts given array [arr] of numbers using Comb Sort
    """
    arr_size = len(arr)
    # Sets initial size of gap as the length of [arr]
    gap = arr_size

    # Keeps track of whether or not a swap occured during the most recent iteration of the sort
    swapped = True

    # Keeps trying to sort the array while
    while gap != 1 or swapped:

        # Keeps track of whether or not a swap took place in the current iteration
        swapped = False

        # Updates the value of gap for the new iteration
        gap = next_gap(gap)

        for index in range(0, arr_size - gap):
            # Swaps the target indices if the left index is grester than the right index
            if arr[index] > arr[index + gap]:
                arr[index], arr[index + gap] = arr[index + gap], arr[index]
                # Sets [swapped] to true when a swap is done
                swapped = True
    return arr
