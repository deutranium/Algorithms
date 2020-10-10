// C# program for implementation of Comb Sort 
using System; 
  
class GFG 
{ 
    // To find gap between elements 
    static int getNextGap(int gap) 
    { 
        // Shrink gap by Shrink factor 
        gap = (gap*10)/13; 
        if (gap < 1) 
            return 1; 
        return gap; 
    } 
  
    // Function to sort arr[] using Comb Sort 
    static void sort(int []arr) 
    { 
        int n = arr.Length; 
  
        // initialize gap 
        int gap = n; 
  
        // Initialize swapped as true to  
        // make sure that loop runs 
        bool swapped = true; 
  
        // Keep running while gap is more than  
        // 1 and last iteration caused a swap 
        while (gap != 1 || swapped == true) 
        { 
            // Find next gap 
            gap = getNextGap(gap); 
  
            // Initialize swapped as false so that we can 
            // check if swap happened or not 
            swapped = false; 
  
            // Compare all elements with current gap 
            for (int i=0; i<n-gap; i++) 
            { 
                if (arr[i] > arr[i+gap]) 
                { 
                    // Swap arr[i] and arr[i+gap] 
                    int temp = arr[i]; 
                    arr[i] = arr[i+gap]; 
                    arr[i+gap] = temp; 
  
                    // Set swapped 
                    swapped = true; 
                } 
            } 
        } 
    } 
  
    // Driver method 
    public static void Main() 
    { 
        int []arr = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0}; 
        sort(arr); 
  
        Console.WriteLine("sorted array"); 
        for (int i=0; i<arr.Length; ++i) 
            Console.Write(arr[i] + " "); 
  
    } 
} 