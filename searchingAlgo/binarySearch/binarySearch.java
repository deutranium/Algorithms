import java.io.*;

class BinarySearch { 
    static int search(int arr[], int value, int leftIndex, int rightIndex) {
        // base case
        if (rightIndex < leftIndex) {
            return -1;
        }

        // calculate the mid index
        int midIndex = (rightIndex - leftIndex) / 2;
        midIndex += leftIndex;

        // if value is same as value on midIndex, simply return midIndex
        if (value == arr[midIndex]) {
            return midIndex;
        } else if (value < arr[midIndex]) {
            // when value is less than middle value, we search in the left half
            return search(arr, value, leftIndex, midIndex - 1);
        } else {
            // when value is greater than middle value, we search in the right half
            return search(arr, value, midIndex + 1, rightIndex);
        }
    }

    public static void main(String args[]) {
        // sorted array to search the value in
        int arr[] = { 10, 13, 15, 22, 89, 90 };
        // value to search for
        int value = 15; 

        // find the value
        int result = search(arr, value, 0, arr.length - 1);

        // show the result
        if (result == -1) {
            System.out.println("Item not found");
        } else {
            System.out.println("Item found at index: " + result);
        }
    }
} 
