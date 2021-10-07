#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
   int j;
   for (int i = 1; i < n; i++)
   {
      int key = arr[i];
      j = i - 1;

      /*Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
      while ( j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
}

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main()
{
   int arr[] = {1,9,2,8,3,7,4};
   int n = sizeof(arr) / sizeof(arr[0]);

   insertionSort(arr, n);
   printArray(arr, n);

   return 0;
}

