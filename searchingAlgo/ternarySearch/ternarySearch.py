def ternarySearch(arr, x, lo, hi):
	mid1 = lo + (hi - lo)//3
	mid2 = lo + 2 * (hi - lo)//3

	if x < arr[mid1]:
		return(ternarySearch(arr, x, 0, mid1))
	elif x == arr[mid1]:
		return mid1
	elif x < arr[mid2]:
		return ternarySearch(arr, x, mid1 + 1, mid2)
	elif x == arr[mid2]:
		return mid2
	else:
		return ternarySearch(arr, x, mid2 + 1, hi)

# Testcase
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
x = 2

try:
	print(ternarySearch(arr, x, 0, len(arr)))
except:
	print(-1)
