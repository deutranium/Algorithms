# Testcase
arr = [63, 1, 103, 3, 8, 74, 76, 37, 71, 66]
l = len(arr)

def mergeSort(arr):
	l = len(arr)
	mid = l//2

	if l <= 1:
		return arr

	left = arr[:mid]
	right = arr[mid:]			#_______
								#	  	|
	left = mergeSort(left)		#       |____ Understand
	right = mergeSort(right)	#		|     this properly!
								#_______|
								#
	return merge(left, right)


def merge(arr1, arr2):
	arr = []
	l1 = len(arr1)
	l2 = len(arr2)

	while((l1 != 0) and (l2 != 0)):
		if arr1[0] > arr2[0]:
			arr.append(arr2[0])
			del arr2[0]
			l2 -= 1
		elif arr1[0] < arr2[0]:
			arr.append(arr1[0])
			del arr1[0]
			l1 -= 1
		else:
			arr.append(arr1[0])
			arr.append(arr2[0])
			del arr2[0]
			del arr1[0]
			l1 -= 1
			l2 -= 1

	if l1 == 0:
		arr.extend(arr2)
	else:
		arr.extend(arr1)

	return arr

print(mergeSort(arr))
