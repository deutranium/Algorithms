# Testcase
arr = [1, 63, 103, 3, 8, 74, 76, 37, 71, 66]
l = len(arr)

def insertionSort(arr):
	for i in range(1,l):
		if arr[i] < arr[i - 1]:
			for j in range(i):
				if arr[i] < arr[j]:
					x = arr[i]
					del arr[i]
					arr.insert(j, x)
	return arr

print(insertionSort(arr))

