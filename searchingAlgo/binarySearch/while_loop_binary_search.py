"""The below code is an algorithm implementing Binary search
	It uses a while loop and has a time complexity of 
	O(N) = log(N)
	Θ(N) = log(N)
	Ω(N) = 1 ( constant )
		"""
def search( arr , X ) : 
	ans = -1
	start = 0
	end = len(arr)

	while end >= start :
		mid = (start+end)//2

		if( arr[mid] == X ):
			ans = mid
			break

		elif ( arr[mid] > X ):
			end = mid -1

		else :
			start = mid +1

	#The solution will be in zero based indexing 
	print( ans )

	

# Testcase
arr = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
x = 2

search( arr , x)
""" The function search() automatically prints the result
 hence a seperate print statement doesn't need to be added
 This can however be easily modified by removing the last 
 statement and adding " return mid "