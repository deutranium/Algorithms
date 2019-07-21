def linearSearch(arr, x):
	for i, val in enumerate(arr):
		if val == x:
			return i

	return -1

# Testcase
arr = ["a", "b", "c", "d"];
x = "b";

print(linearSearch(arr, x))
