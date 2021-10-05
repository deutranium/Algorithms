#include <stdio.h>

void cocktail_sort(int *arr, int length)
{
    int start = 0, end = length - 1, flag = 1, temp;
    while (flag)
    {
        flag = 0;
        for (int i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
            break;
        flag = 0;
        end--;
        for (int i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        start++;
    }
}

void main()
{
    int arr[] = {54, 74, 98, 154, 98, 32, 20, 13, 35, 40}, size = sizeof(arr) / sizeof(arr[0]);
    printf("array before: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\nperforming cocktail sort...");
    cocktail_sort(arr, size);
    printf("\narray after: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}