def recur(arr, x, lo, hi):
	mid = (lo + hi)//2

	if x == arr[mid]:
		return mid
	elif x > arr[mid]:
		return(recur(arr, x, mid, hi))
	else:
		return(recur(arr, x, lo, mid))

# Sample testcase - an array sorted in ascending order
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
l = len(arr)
x = 2

try:
	print(recur(arr, x, 0, len(arr)))
except:
	print(-1)
