function binarySearch(arr, x) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    let mid = Math.round((left + right) / 2); // calculate the mid index

    // if value is same as value on midIndex, simply return midIndex
    if (arr[mid] == x) {
      return mid;
    }

    // when value is less than middle value, we search in the left half
    if (arr[mid] < x) {
      left = mid + 1;

      // when value is greater than middle value, we search in the right half
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

// testCase
// sorted array to search the value in
const arr = [2, 12, 23, 34, 45, 52, 61, 75, 85, 99];
const x = 85;

console.log(binarySearch(arr, x));
