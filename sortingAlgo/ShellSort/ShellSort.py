'''Shell sort is an algorithm that first sorts the elements far apart
from each other and successively reduces the interval between the elements
to be sorted. It is a generalized version of insertion sort.'''



def shellSort(array, n):
    interval = n // 2                  # Rearrange elements at each n/2, n/4, n/8, ... intervals
    while interval > 0:
        for i in range(interval, n):
            temp = array[i]
            j = i
            while j >= interval and array[j - interval] > temp:
                array[j] = array[j - interval]
                j -= interval

            array[j] = temp
        interval //= 2

#TEST CODE
        
data = [9, 8, 3, 7, 5, 6, 4, 1]
size = len(data)
shellSort(data, size)
print('Sorted Array in Ascending Order:')
print(data)
