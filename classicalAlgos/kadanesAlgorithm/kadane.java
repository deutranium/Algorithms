
// Kadane's Algorithm
public int kandaneForMaxSubArray(int[] arr) {
 int maxEndHere = 0;
 int maxSoFar = 0;
 for (int i = 0; i < arr.length; i++) {
 maxEndHere += arr[i];
 if (maxEndHere < 0) {
 maxEndHere = 0;
 }
 if (maxSoFar < maxEndHere) {
 maxSoFar = maxEndHere;
 }
 }
 return maxSoFar;
 }