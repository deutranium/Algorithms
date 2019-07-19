def linearSearch(arr, x):
	for i, val in enumerate(arr):
		if val == x:
			return i

	return -1

# Sample input
arr = ["a", "b", "c", "d"];
x = "b";

print(linearSearch(arr, x))
