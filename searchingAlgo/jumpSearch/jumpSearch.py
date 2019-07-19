import math

def jumpSearch(arr, x):
	l = len(arr)
	step = math.floor(math.sqrt(l))
	for i in range(0, l - 1, step):
		if arr[i] > x:
			return(linearSearch(arr[(i - step):i], x, (i - step)))
	return -1


def linearSearch(arr, x, minIndex):
	for i, val in enumerate(arr):
		if val == x:
			return i + minIndex

	return -1

print(jumpSearch([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 4))
