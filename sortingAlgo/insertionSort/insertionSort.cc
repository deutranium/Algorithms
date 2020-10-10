#include<iostream>

using namespace std;

void insertionsort(int a[], int n) {
    for(int i = 1; i < n; ++i) {
        int j = i-1;
        int key = a[i];
        while(j > -1 && a[j] > key) {
            swap(a[j+1], a[j]);
            --j;
        }
        a[j+1] = key;
    }
}

void insertionsort_rec(int a[], int n) {
    if(n < 2) return;
    insertionsort_rec(a, n-1);
 
    int key = a[n-1];
    int j = n-2;

    while(j > -1 && a[j] > key) {
        swap(a[j+1], a[j]);
        --j;
    }

    a[j+1] = key;

}

int main() {
    int arr[10] = {3, 450, 12, 4, -1, 0, 24, 95, 123, 0};
    for(int i = 0; i < 10; ++i)
        cout << *(arr+i) << ' ';
    cout << endl;
    insertionsort_rec(arr, 10);
    for(int i = 0; i < 10; ++i)
        cout << *(arr+i) << ' ';
    return 0;
}
