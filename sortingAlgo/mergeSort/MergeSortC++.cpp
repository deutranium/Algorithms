/* Merge Sort is based on Divide and Conquer, which means we divide a problem to smaller subproblems and try to solve those
    small subproblem individually to come up with a solution.

    We can say that an array of single element is always sorted.Merge sort is based on this property only. We divide the whole array in smaller parts and sort them.
    Then we merge this sorted arrays to recover back our original array

    ex:                                                                   3 5 4 1 2              UNSORTED ARRAY
                                                                              |
                                                                          ----------
                                                                          |         |
                                                                         3 5      4 1 2         DIVIDED IN TWO SMALLER ARRAYS
                                                                          |         |
                                                                        -----   ------------    FURTHER DIVIDED
                                                                        |   |   |          |  
                                                                        3   5   4         1 2     3,4,5 ARE SORTED IN ITSELF
                                                                        \   /   |          |
                                                                         3 5    |         ----     MERGING SORTED ARRAYS CONTAINING 3 AND 5 AND FURTHER DIVIDING 1 2
                                                                          |     |         |   |
                                                                          |     |         1   2    1, 2 SORTED IN ITSELF
                                                                          |      \        \   /
                                                                          |       \        1 2     MERGED TWO SORTED ARRAYS
                                                                           \       \       /
                                                                            \       \     /
                                                                             \       \   /
                                                                              \      1 2 4         MERGED TWO SORTED ARRAYS ([4] , [1,2])
                                                                               \       /
                                                                                \     /
                                                                               1 2 3 4 5            MERGED TWO SORTED ARRAYS ([1,2,4], [3,5])

    ALGORITHM :
    Merge_sort (arr, left, right)

        if left < right                                                    // Check for base case
             THEN mid <= left+(right-left)/2
                merge_sort(arr,left,mid)
                merge_sort(arr, mid+1, right)
                merge(arr, l,r);
      else 
        return
    endif                    
    */
#include<bits/stdc++.h>  //header file
using namespace std;

vector<int> temp; // temporary vector to store the merged array
void merge(vector<int> &arr, int left, int right)
{
    if(left>=right)                                             //either the array is not valid or conatains only 1 element , which is already sorted
        return;
    int mid= left+(right-left)/2;                       //equivalent to (left+right)/2 and prevents overflow
    int p1=left,p2=mid+1,p3=left;                       // p1, p2 is pointer for 1st and second sorted array respectively, p3 is pointer for merged array
    while(p1<=mid && p2<=right)                         // while p1 and p2 both points to a valid elements
    {
        if(arr[p1]<arr[p2])                             // the element pointed by p1 is smaller than element pointed by p2
        {
            temp[p3]=arr[p1++];                         // adding arr[p1] to the merged array and incrementing p1
        }
        else                                            // the element pointed by p2 is smaller than element pointed by p1
        {
            temp[p3]= arr[p2++];                        // adding arr[p1] to the merged array and incrementing p2
        }
        p3++;                                           // incrementing p3 for additon at next position 
    }
    while(p2<=right)                                   // this means 1st array is exhausted, but elemnents are left in second array
    {
        temp[p3++]=arr[p2++];                          // since the elements are sorted, directly copying the contents
    }
    while(p1<=mid)                                     // this means 2nd array is exhausted, but elemnents are left in first array
    {
        temp[p3++]=arr[p1++];                          // since the elements are sorted, directly copying the contents
    }
    for(int i=left;i<=right;i++)                       // copying thr contents of the merged array stored in temp to the original array
    {
        arr[i]=temp[i];
    }
}

void mergesort(vector<int> &arr, int left, int right)    // merge sort function taking 3 arguments ,the array to be sorted, starting index, ending index
{
    if(left>=right)                                      //either the array is not valid or conatains only 1 element , which is already sorted
        return ;
    int mid =left+(right-left)/2;                        // equivalent to (left+right)/2 and prevents overflow
    mergesort(arr, left, mid);                           // Dividing array in smaller parts and applying merge sort
    mergesort(arr, mid+1, right);                        // Dividing array in smaller parts and applying merge sort
    merge(arr, left,right);                              // merges the two sorted array obtained from above
}

int main()                                         //main function
{
    
   int n,i,j;
   cin>>n;                                                       //size of the array
   vector<int> arr(n);                                           //defining the vector of size n
   temp.resize(n);                                               // resizing the temporary vector as per the user input.
   for(i=0;i<n;i++)
   {
       cin>>arr[i];                                             // taking inputs
   }
   mergesort(arr, 0, n-1);                                     // Called merge sort on the arr
   for(i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";                                       // Output Sorted array in non decreasing manner
   }
   return 0;
}

// TESTRUN
/* INPUT : 10
           0 1 2 3 4 5 6 7 8 9 


    Time Complexity O(nlogn)  n: size of the array
    Space Complexity : O(n)   n: size of the array
*/