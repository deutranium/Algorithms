import java.util.Arrays;

public class ShellSort { 
    public static int[] shellSort(int arr[]) { 
        int n = arr.length; 
        // Start with a big gap, then reduce the gap 
        for (int gap = n/2; gap > 0; gap /= 2) { 
            // add a[i] to the elements that have been gap 
            // sorted save a[i] in temp and make a hole at 
            // position i 
            for (int i = gap; i < n; i += 1) { 
                int temp = arr[i]; 
                // shift earlier gap-sorted elements up until 
                // the correct location for a[i] is found
                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap]; 
                } 
                // put temp (the original a[i]) in its correct 
                // location
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