/*
In computer science, the maximum sum subarray problem is the task of finding a contiguous 
subarray with the largest sum, within a given one-dimensional array A[1...n] of numbers. 
Formally, the task is to find indices i and j with 1 <= i <= j <= n such that the sum of 
the elements in the range [i, j] is as large as possible.

Each number in the input array A could be positive, negative, or zero.

This problem can be solved using Kadane's Algorithm

source : https://en.wikipedia.org/wiki/Maximum_subarray_problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Returns the max of 2 numbers */
int Max(int a, int b) {
    return (a > b) ? a : b;
}

/* 
We iterate through each element and consider taking it. If the current sum after taking 
the element is more than the element this could be a probable answer and we take it. 
Otherwise if taking the number causes current sum to decrease below the element, we 
remove the entire previous subarray and consider a new subarray starting from the 
current element by taking its value as the current sum. 
In every iteration we update the answer variable to the max of itself and current sum 
*/

int kadanesAlgo(int *a, int n) {
    int i = 0, currSum = 0, ans = INT_MIN;
    for(i = 0; i < n; i++) {
        currSum += a[i];                        
        currSum = Max(currSum, a[i]);           /* if currSum ever falls below a[i], we will then start a new subarray by taking a[i] as currSum */
        ans = Max(ans, currSum);                /* updating ans to the max of currSum and ans */
    }
    return ans;
}

int main() {
    int *a, n, i;
    printf("enter the number of elements : ");
    scanf("%d", &n);

    if(!n) {
        printf("exiting!!!");
        return 0;
    }

    a = (int*)malloc(n * sizeof(int));

    /* Generates error if array could not be created */
    if(a == NULL){
        printf("array could not be created");
        return 0;
    }

    printf("enter the elements:\n");
    for(i = 0; i < n; i++) {
        printf("enter element %d : ", i + 1);
        scanf("%d",&a[i]);
    }

    printf("the longest subarray sum is %d", kadanesAlgo(a, n));
    return 0;
}

/*
Time complexity : O(n) (best, worst and average are all same)
Space complexity : O(1) => constant
*/