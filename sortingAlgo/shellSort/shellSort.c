#include <stdio.h>

void shellsort(int arr[], int num)
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int i = num / 2; i > 0; i /= 2)
    {
        for (int j = i; j < num; j++)
        {
            for (int k = j - i; k >= 0; k -= i)
            {
                if (arr[k + i] >= arr[k])
                    break;
                //swap the elements if the element is larger than the next element
                else
                {
                    int tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}

/**
 * Driver code.
 */
int main()
{
    int arr[] = {11, 24, 53, 46, 55, 60, 17, 58, 29, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    shellsort(arr, size);

    for (int k = 0; k < size; k++)
        printf("%d ", arr[k]);
    printf("\n");

    return 0;
}

/*
TIme Complexity : O(nlog(n))
Space Complexity : O(1)
*/