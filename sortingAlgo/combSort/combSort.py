'''Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares
adjacent values. So all inversions are removed one by one. Comb Sort improves on Bubble
Sort by using gap of size more than 1. The gap starts with a large value and shrinks by
a factor of 1.3 in every iteration until it reaches the value 1. Thus Comb Sort removes
more than one inversion counts with one swap and performs better than Bubble Sort.'''


# Python program for implementation of CombSort 


def comb_sort(alist):
    def swap(i, j):
        alist[i], alist[j] = alist[j], alist[i]
 
    gap = len(alist)
    shrink = 1.3
 
    no_swap = False
    while not no_swap:
        gap = int(gap/shrink)
 
        if gap < 1:
            gap = 1
            no_swap = True
        else:
            no_swap = False
 
        i = 0
        while i + gap < len(alist):
            if alist[i] > alist[i + gap]:
                swap(i, i + gap)
                no_swap = False
            i = i + 1
 
#TEST CODE 
alist = input('Enter the list of numbers separated by space: ').split()
alist = [int(x) for x in alist]
comb_sort(alist)
print('Sorted list: ', end='')
print(alist)
