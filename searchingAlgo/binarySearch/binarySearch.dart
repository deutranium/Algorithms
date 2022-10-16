/// search an element in array with binary search
/// [arr] list of integer
/// [x] int we want to search
/// [left] low index of array
/// [right] high index of array
int binarySearch(List<int> arr, int x, int left, int right) {
  ///  mid index of selected array
  int mid = left + (right - left) ~/ 2;

  // return -1 if x not in array
  if (mid >= arr.length || right < 1) {
    return -1;
  }

  // if value is equal to element in array mid index, return the index
  if (x == arr[mid]) {
    return mid;

    // if value is bigger than elemnt in array mid, search in the right half
  } else if (x > arr[mid]) {
    return binarySearch(arr, x, mid + 1, right);

    // otherwise search for the left half
  } else {
    return binarySearch(arr, x, left, mid - 1);
  }
}

/// Testcase 1
var arr = [1, 5, 2, 3, 4, 5, 6, 7, 8, 9];
var x = 0;

/// Testcase 2
var arr2 = [1, 5, 2, 3, 4, 100, 6, 7, 11, 9];
var x1 = 1;

void main(List<String> args) {
  /// expect return equal to -1
  print(binarySearch(arr, x, 0, arr.length));

  /// expect return equal to 0
  print(binarySearch(arr, x1, 0, arr.length));
}
