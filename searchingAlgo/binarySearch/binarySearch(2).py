#import time
#startTime = time.time()

def recur(arr, x, lI, uI):
	mI = (lI + uI)//2

	if x == arr[mI]:
		return mI
	elif x > arr[mI]:
		return(recur(arr, x, mI, uI))
	else:
		return(recur(arr, x, lI, mI))

def main(x):
	try:
		return(recur(arr, x, 0, len(arr)))
	except:
		return -1

# An array sorted in ascending order
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

l = len(arr)
x = 0

print(main(x))

#for i in range(10000):
#	main(i % 10)

#endTime = time.time()

#print("time: " + str(endTime - startTime))


"""

"""

