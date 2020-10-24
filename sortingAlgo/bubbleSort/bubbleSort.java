import java.util.Arrays;

public class bubbleSort {
  
  public static void bubbleSort(int[] arr) {
    int temp;
    for (int i = 0; i < arr.length-1; i++) {
      for (int j = 0; j < arr.length-1-i; j++) {
        if (arr[j] > arr[j+1]) {
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
  }
  
  public static void main(String[] args) {
    int[] arr = new int[]{1, 31, 3, 3, 8, 71, 28, 37, 71, 33, 10, 40};
    bubbleSort(arr);
    System.out.println(Arrays.toString(arr));
  }
}
