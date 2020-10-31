def cycleSort(input):
    writes = 0
    # Loop through the array to find cycles to rotate. 
    for cycleStart, item in enumerate(input):
        # Find where to put the item. 
        pos = cycleStart
        for item2 in input[cycleStart + 1:]:
            if item2 < item:
                pos += 1

        if pos == cycleStart:
            continue
        # Otherwise, put the item there or right after any duplicates.
        while item == input[pos]:
            pos += 1
        input[pos], item = item, input[pos]
        writes += 1
        # Rotate the rest of the cycle. 
        while pos != cycleStart:
            pos = cycleStart
            for item2 in input[cycleStart + 1:]:
                if item2 < item:
                    pos += 1
            # Put the item there or right after any duplicates. 
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