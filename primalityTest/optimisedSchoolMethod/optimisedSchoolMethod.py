import math

def optimisedSchoolMethod():
	n = int(input())

	if(n <= 1):
		return False

	if (n % 2 == 0) or (n % 3 == 0):
		return False

	for i in range(5, math.round(math.sqrt(n)), 6):
		if n % i == 0:
			return False

	return True
optimisedSchoolMethod()
#https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/
