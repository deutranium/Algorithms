// Implementing Kadanes algorithm in java
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;     // Importing util package for getting user input(Scanner class)
public class Main
{
    int kadanesAlgorithm(int arr[], int n){
        int count=0;    // count of negative elements
        int max1=arr[0];
        int max=0;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                count++;
            }
        }
        if(count==n){
            for(int i=1;i<n;i++){
                if(arr[i]>max1){
                    max1=arr[i];
                }
            }
            return max1;
        }
        else{
            int sum=0;
            max=arr[0];
            for(int i=0;i<n;i++){
                sum=sum+arr[i];
                if(sum<0){  //if sum till current index gets less than 0, then reset it to 0
                    sum=0;
                }
                if(sum>max){    //if sum till current index gets more than max, then set max to current sum
                    max=sum;    
                }
            }
        }
        return max;
    }
	public static void main(String[] args) {    // main function
		Main obj=new Main();
        int n;  // n: size of array
        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter array size: ");  
        n=sc.nextInt();  
        int[] array = new int[n];  // array: input array
        System.out.println("Enter array elements: ");  
        for(int i=0; i<n; i++)  
        {  
        array[i]=sc.nextInt();  // input array elements
        }
        System.out.println("Maximum sum of subarray: "+obj.kadanesAlgorithm(array,n)); // output
	}
}

/*Explanation:
Here we will traverse the array and we will see whether all 
elements in the array are negative or not. 

If all the elements are negative then we will simply take one element 
max1 and after iterating the array we will see if any other element has 
a value less than that (in a negative sense ) then we modify the value of max1.

Else there will mix of positive and negative elements. In that case, we will 
have one element max which will point to arr[0]. Then while traversing we will 
see if the sum of an incoming element with the existing sum variable is negative we
will modify the value of the sum variable to 0 else we will traverse further. 
While traversing we will also keep the look at the value of max if anytime it 
is more than the sum we will modify it.

Time:O(N) Iterating loop.

Space:O(1) Not using any additional data structure.*/





    



