#TC
arr = [10, 7, 8, 1, 4, 2, 5]

def countingSort(arr, k, key=(lambda x:x)):
    table = [[] for _ in range(k+3)]

    for n in arr:
        table[key(n)].append(n)

    arr = []
    for i in table:
        arr.extend(i)
    return arr

def radixSort(arr, k):
    b = len(arr) # base for radix sort
    
    #calculate number of digits in k when in base b
    d = 0
    copy = k
    while copy:
        d+=1
        copy/=b
    
    for pos in range(d):
        arr = countingSort(arr, k, lambda x : (x//(b**pos))%b )
    
    return arr

print(radixSort(arr, 15))
