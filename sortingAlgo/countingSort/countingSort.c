#include <stdio.h>

int main() {
    int arrayLength;
    printf("How many numbers do you want to sort? ");
    scanf("%d",&arrayLength);
    int array[arrayLength];
    int sortedArray[arrayLength];
    int largest = 0;
    for (int i = 0; i < arrayLength; i++) {
        printf("%d. number:",i+1);
        int j;
        scanf("%d", &j);
        if (j > largest) {
            largest = j;
        }
        array[i] = j;
    }
    int count[largest+1];
    for(int i = 0; i < largest+1; i++) {
        count[i] = 0;
    }
    for(int i = 0; i < arrayLength; i++) {
        count[array[i]]++;
    }
    for(int i = 1; i < largest+1; i++) {
        count[i] += count[i-1];
    }
    for(int i = 0; i < arrayLength; i++) {
        sortedArray[count[array[i]]-1] = array[i];
        count[array[i]] -= 1;
    }
    printf("\nSorted array: ");
    for(int i = 0; i < arrayLength; i++) {
        printf("%d ",sortedArray[i]);
    }
    return 0;
}
