# Testcase
arr = [1, 63, 103, 3, 8, 74, 76, 37, 71, 66]
lMinusOne = len(arr) - 1

def bubbleSort(arr):
	while True:
		swapped = False
		for i in range(lMinusOne):
			if arr[i] > arr[i + 1]:
				swapped = True
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
		if swapped == False:
			return arr

print(bubbleSort(arr))
