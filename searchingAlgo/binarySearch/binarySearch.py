def search(arr, x, lo, hi):	# hi = index of last element + 1
	idx = (lo + hi)//2

	if (lo == hi - 1) and (arr[lo] != x) and (arr[hi] != x):
		return -1
	elif x == arr[idx]:
		return idx
	elif x > arr[idx]:
		return(search(arr, x, idx, hi))
	else:
		return(search(arr, x, 0, idx))

# Sample testcase - an array sorted in ascending order
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
l = len(arr)
x = 2

print(search(arr, x, 0, l)) # Why not (len(arr) - 1)??
