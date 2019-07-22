# Testcase
arr = [63, 1, 103, 3, 8, 74, 76, 37, 71, 66]
l = len(arr)

def selectionSort(arr):
	for i in range(l):
		idx = i
		iPlusOne = i + 1
		for j in range(iPlusOne, l):
			if arr[j] < arr[idx]:
				idx = j

		arr[i], arr[idx] = arr[idx], arr[i]
	return arr

print(selectionSort(arr))
