def cycleSort(input):
    writes = 0
    
    for cycleStart, item in enumerate(input):
        pos = cycleStart
        for item2 in input[cycleStart + 1:]:
            if item2 < item:
                pos += 1

        if pos == cycleStart:
            continue
 
        while item == input[pos]:
            pos += 1
        input[pos], item = item, input[pos]
        writes += 1
 
        while pos != cycleStart:
            pos = cycleStart
            for item2 in input[cycleStart + 1:]:
                if item2 < item:
                    pos += 1
            while item == input[pos]:
                pos += 1
            input[pos], item = item, input[pos]
            writes += 1
    return input

arr = [11, 8, 23, 5, 10, 12, 2, 14, 11, 9, 4, 4, 6, 24 ]
print("Before:"+str(arr))
n = len(arr)  
result = cycleSort(arr)
print("After:"+str(result))