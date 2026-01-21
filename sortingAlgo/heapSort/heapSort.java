import java.util.*;
import java.io.*;
import java.lang.*;
  
public class HeapSort 
{   
    // building the heap
	public void buildheap(int arr[],int n){
        for (int i = n / 2 - 1; i >= 0; i--) 
		    heapify(arr, n, i);
    }
    
    

	public void sort(int arr[]) 
	{ 
		int n = arr.length; 

		buildheap(arr,n); 
        // One by one extract an element from heap
		for (int i=n-1; i>0; i--) 
		{ 
			 
			int temp = arr[0]; 
			arr[0] = arr[i]; 
			arr[i] = temp; 
            // call max heapify
			heapify(arr, i, 0); 
		} 
	} 
    
    
    // To heapify a subtree rooted with node i 
    void heapify(int arr[], int N, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
  
        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;
  
        // If right child is larger than largest so far
        if (r < N && arr[r] > arr[largest])
            largest = r;
  
        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
  
            // Recursively heapify the affected sub-tree
            heapify(arr, N, largest);
        }
    }
    // function to print array of size n
	static void printArray(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 
    
    
	public static void main(String args[]) 
	{ 
		int arr[] = {25, 4, 13, 84, 35, 7}; 
		int n = arr.length; 

		HeapSort arrnew = new HeapSort(); 
		arrnew.sort(arr); 

		System.out.println("Sorted array is"); 
		printArray(arr); 
	} 
} 
