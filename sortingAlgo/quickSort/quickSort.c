#include <stdio.h>
void swap(int array[] ,int index1, int index2);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main() {
    int array[9] = {2,9,3,8,6,5,4,7,10};
    printf("Original array: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }

    quickSort(array, 0,9);

    printf("\nSorted array: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void swap(int array[], int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}




int partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = 0;
    int j = high;

    while(i < j) {
        do {
            i++;
        } while (array[i] <= pivot);

        do {
            j--;
        } while (array[j] > pivot);
        if (i < j) {
            swap(array, i, j);
        }
    }
    swap(array, low, j);
    return j;
}


void quickSort(int array[], int low, int high) {
    if (low < high) {
        int j = partition(array, low, high);
        quickSort(array, low, j);
        quickSort(array, j+1, high);
    }
}
