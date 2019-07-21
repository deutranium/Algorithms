def exponentialSearch(arr, x, lo, hi):
	if arr[hi] >= x:
		return(binarySearch(arr, x, lo, hi + 1))
	else:
		return(exponentialSearch(arr, x, hi, hi * 2))


def binarySearch(arr, x, lo, hi):	# `hi` as one greater than the index of the last element present in the array
	idx = (lo + hi)//2

	if x == arr[idx]:
		return idx
	elif x > arr[idx]:
		return(binarySearch(arr, x, idx, hi))
	else:
		return(binarySearch(arr, x, 0, idx))

# Testcase
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
x = 2

try:
	print(exponentialSearch(arr, x, 0, 1))
except:
	print(-1)
