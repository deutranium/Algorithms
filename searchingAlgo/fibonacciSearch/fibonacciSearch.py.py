# return the fibonacci number at the index of n
def FibonacciGenerator(n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        return FibonacciGenerator(n - 1) + FibonacciGenerator(n - 2)

# return the index at which x exists inside arr
# return -1 otherwise

def FibonacciSearch(arr, x):

    # find the smallest Fibonacci number greater than or equal
    # to the length of arr
    m = 0 
    while FibonacciGenerator(m) < len(arr): # 
        m = m + 1 

    offset = -1
    while (FibonacciGenerator(m) > 1):

        i = min( offset + FibonacciGenerator(m - 2) , len(arr) - 1)

        if (x > arr[i]):

            m = m - 1
            offset = i

        elif (x < arr[i]):

            m = m - 2

        else:

            return i

    # this will run if there is one last element left
    if(FibonacciGenerator(m - 1) and arr[offset + 1] == x):
        return offset + 1

    # return -1 if the element doesn't exist in the array
    return -1


# the search array
print("Enter array : ", end='')
arr = list(map(int, input().split()))

x = int(input("Enter number to be searched : "))
#if array is not sorted.
print(FibonacciSearch(sorted(arr), x))
#if array is sorted
#print(FibonacciSearch(arr, x))