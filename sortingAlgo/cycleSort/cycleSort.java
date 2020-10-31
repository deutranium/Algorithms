import java.util.*; 
  
public class cycleSort { 
    public static int[] cycleSort(int arr[]) { 
        int writes = 0; 
        int n = arr.length;
        // traverse array elements and put it to on 
        // the right place 
        for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) { 
            int item = arr[cycle_start]; 
            // Find position where we put the item. We basically 
            // count all smaller elements on right side of item.
            int pos = cycle_start; 
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) 
                    pos++; 
            }
            // If item is already in correct position 
            if (pos == cycle_start){ 
                continue; 
            }
            // ignore all duplicate elements
            while (item == arr[pos]) {
                pos += 1; 
            }
            // put the item to it's right position 
            if (pos != cycle_start) { 
                int temp = item; 
                item = arr[pos]; 
                arr[pos] = temp; 
                writes++; 
            } 
  
            // Rotate rest of the cycle 
            while (pos != cycle_start) { 
                pos = cycle_start; 
                // Find position where we put the element 
                for (int i = cycle_start + 1; i < n; i++){  
                    if (arr[i] < item) 
                        pos += 1; 
                } 
                // ignore all duplicate elements 
                while (item == arr[pos]){
                    pos += 1; 
                } 
                // put the item to it's right position 
                if (item != arr[pos]) { 
                    int temp = item; 
                    item = arr[pos]; 
                    arr[pos] = temp; 
                    writes++; 
                } 
            } 
        }
        return arr; 
    } 


    public static void main(String[] args) { 
        int arr[] = {11, 8, 23, 5, 10, 12, 2, 14, 11, 9, 4, 4, 6, 24 } ; 
        System.out.println("Before sort : "+Arrays.toString(arr));
        
        int result[] = cycleSort(arr); 
  
        System.out.println("After sort : "+Arrays.toString(result)); 
    } 
} 