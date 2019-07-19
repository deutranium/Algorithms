def linearSearch(arr, x):
	for i, val in enumerate(arr):
		if val == x:
			return i

	return -1

"""
arr = input("Enter space separated items\n").split()
x = input("To search for?\n")
"""

# Sample input
arr = ["a", "b", "c", "d"];
x = "b";

print(linearSearch(arr, x))
