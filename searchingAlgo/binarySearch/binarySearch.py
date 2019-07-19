#import time

#beginTime = time.time()

# An array sorted in ascending order
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
l = len(arr)
x = 0

def search(x, start, end, arr):
	idx = (start + end)//2

	if (start == end - 1) and (arr[start] != x) and (arr[end] != x):
		return -1
	elif x == arr[idx]:
		return idx
	elif x > arr[idx]:
		return(search(x, idx, end, arr))
	else:
		return(search(x, 0, idx, arr))

print(search(x, 0, len(arr), arr)) # Why not (len(arr) - 1)??


#for i in range(10000):
#	search(i % 10, 0, l, arr)
#	# Why not (l - 1)??
#
#endTime = time.time()

#print("time: " + str(endTime - beginTime))
