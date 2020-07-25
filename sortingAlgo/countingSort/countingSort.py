#TC
arr = [10, 7, 8, 1, 4, 2, 5]

def countingSort(arr, key=(lambda x:x), k=-1):
    if k==-1:
        k=max(arr)
        
    table = [[] for _ in range(k+3)]

    for n in arr:
        table[key(n)].append(n)

    arr = []
    for i in table:
        arr.extend(i)
    return arr

print(countingSort(arr, 15))
