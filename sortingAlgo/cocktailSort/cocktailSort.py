# cocktail sort function
def cocktailSort(A):
    up = range(len(A)-1)
    while True:
        for indices in (up, reversed(up)):
            
            # reseting the swapped flag
            swapped = False
            
            # looping through left to right
            for i in indices:
                if A[i] > A[i+1]:
                    A[i], A[i+1] =  A[i+1], A[i]
                    swapped = True
            
            # if noting is swapped means, array is sorted
            if not swapped:
                return
 
# initializing the array
array = [25,1,-2,70,100,-10,40,2,0,5]
print("Array before sorting: ",array)
 
cocktailSort(array)
print("Array after sorting: ",array)