import java.util.*; 
  
public class cycleSort { 
    public static int[] cycleSort(int arr[]) { 
        int writes = 0; 
        int n = arr.length;
        for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) { 
            int item = arr[cycle_start]; 
            int pos = cycle_start; 
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) 
                    pos++; 
            }
            if (pos == cycle_start){ 
                continue; 
            }
            while (item == arr[pos]) {
                pos += 1; 
            }
            
            if (pos != cycle_start) { 
                int temp = item; 
                item = arr[pos]; 
                arr[pos] = temp; 
                writes++; 
            } 
  
            
            while (pos != cycle_start) { 
                pos = cycle_start; 
                for (int i = cycle_start + 1; i < n; i++){  
                    if (arr[i] < item) 
                        pos += 1; 
                } 

                while (item == arr[pos]){
                    pos += 1; 
                } 

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