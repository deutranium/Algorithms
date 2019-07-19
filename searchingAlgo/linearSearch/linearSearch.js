function search(arr, x){
	for(i = 0, lgt = arr.length; i < lgt; i++) {
		if(arr[i] == x) return i;
	}
	return -1
}

// Sample input
arr = ["a", "b", "c", "d"];
x = "b";

console.log(search(arr, x));
