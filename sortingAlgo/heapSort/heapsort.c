/*
In computer science, heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. Unlike selection sort, heapsort does not waste time with a linear-time scan of the unsorted region; rather, heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step
source : https://en.wikipedia.org/wiki/Heapsort
*/

#include <stdio.h>
#include <stdlib.h>

/* Creates a max-heap */
void maxHeapify(int a[], int pos, int n){
    int maxpos = pos, temp;
    
    int l_child = 2 * pos + 1;
    int r_child = 2 * pos + 2;
    
    /* compares the current element with its left and right child and takes the max of all 3 to make it the parent */
    if(l_child < n && a[l_child] > a[maxpos])   maxpos = l_child;
    if(r_child < n && a[r_child] > a[maxpos])   maxpos = r_child;
    
    if(maxpos != pos){                                    /* swap(maxpos & pos) */
        temp = a[maxpos];
        a[maxpos] = a[pos];
        a[pos] = temp;
        
        /* recursively checks the child */
        maxheapify(a, maxpos, n);
    }
}

void heapSort(int a[], int n){
    int i, temp;
    
    /* build_heap */
    for(i = n/2 - 1; i >= 0; i--){
        maxHeapify(a, i, n);
    }
    
    /* In every iteration of the loop below, we will move the element at the beginning of the array to the end as the element at the beginning of the array is max element after maxheapify fn */
    for(i = n - 1; i > 0; i--){
        /* push a[0] to the end */
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;


        /* prints the state of the heap after every iteration */
        printf("printing the heap after %d iteration: ", n - i);
        for(int j = 0;j <= i; j++)    printf("%d ", a[j]);
        printf("\n");
        
        /* re-establishes heap property */
        maxHeapify(a, 0, i);
    }
}

int main(){
    int *a, n, i, j;
    
    printf("enter size of array: ");
    scanf("%d", &n);
    
    a = (int*)malloc(n * sizeof(int));
    
    /* throws error when array could not be created */
    if(a == NULL){
        printf("array could not be created\n");
        return 0;
    }
    
    for(i = 0; i < n; i++){
        printf("enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    heapSort(a, n);
    
    printf("Sorted Array: ");
    for(j = 0; j < n; j++)    printf("%d ", a[j]);
    printf("\n");
    
    return 0;
}

/*
Time Complexity : nlogn (best, worst and average are all same)
Space Complexity : O(1) => constant 
In place Sort : Yes
Stable Sort : No
*/