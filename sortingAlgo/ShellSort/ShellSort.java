import java.util.Arrays;

public class ShellSort { 
    public static int[] shellSort(int arr[]) { 
        int n = arr.length; 
        for (int gap = n/2; gap > 0; gap /= 2) { 
            for (int i = gap; i < n; i += 1) { 
                int temp = arr[i]; 
                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap]; 
                } 
                arr[j] = temp; 
            } 
        } 
        return arr; 
    } 
  
    public static void main(String args[]) { 
        int arr[] = {11, 8, 23, 5, 10, 12, 2, 14, 11, 9, 4, 4, 6, 24}; 
        System.out.println("Before : "+Arrays.toString(arr)); 
        
        int result[] = shellSort(arr); 
  
        System.out.println("After : "+Arrays.toString(result)); 
    } 
}  