import math

def search(arr, x, lo, hi):
	pos = math.ceil(lo + ((x - arr[lo]) * (hi - lo) / (arr[hi] - arr[lo])))
	if arr[pos] == x:
		return pos
	elif arr[pos] > x:
		return search(arr, x, lo, pos - 1)
	else:
		return search(arr, x, pos + 1, hi)

arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
x = 10

try:
	print(search(arr, x, 0, len(arr) - 1))
except:
	print(-1)
