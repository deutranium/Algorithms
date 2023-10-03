#include <stdio.h>
#include <stdlib.h>

void pigeonhole_sort(int arr[], int n) {
    // Find the minimum and maximum elements in the array
    int minn = arr[0];
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minn) {
            minn = arr[i];
        } else if (arr[i] > maks) {
            maks = arr[i];
        }
    }

    // Calculate the range of possible key values
    int range = maks - minn + 1;

    // Create an array of vectors to hold elements with the same key
    // The size of 'holes' array is equal to the range
    int *holes[range];
    for (int i = 0; i < range; i++) {
        holes[i] = malloc(sizeof(int) * n);
    }

    // Initialize counts for each hole to zero
    int counts[range];

    for (int i = 0; i < range; i++) {
    counts[i] = 0;
    }

    // Distribute elements into the holes based on their keys
    for (int i = 0; i < n; i++) {
        int key = arr[i] - minn;
        holes[key][counts[key]] = arr[i];
        counts[key]++;
    }

    // Copy elements from holes back to the original array
    int j = 0;
    for (int i = 0; i < range; i++) {
        for (int k = 0; k < counts[i]; k++) {
            arr[j] = holes[i][k];
            j++;
        }
        free(holes[i]); // Free the memory allocated for each hole
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    pigeonhole_sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a); // Free the memory allocated for the array 'a'
    return 0;
}


/* here n is the number of elements in the array to be sorted and a[0...n-1] is the array.
input example:
5
5 4 3 2 1 
Output:
1 2 3 4 5
Length of the range of possible key values = N; number of elements in the array =n;
Overall time complexity = O(n+N) ; Overall Space complexity = O(N) */