#include<iostream>
#include<algorithm>

using namespace std;

void selectionsort(int a[], int n) {
    for(int i = 0; i < n-1; ++i) {
        int min = i;
        for(int j = i+1; j < n; ++j) {
            if(a[j] < a[min])
                min = j;
        }

        swap(a[min], a[i]);
    }
}

int min_i(int a[], int i, int j) {
    if(i == j) return i;

    int k = min_i(a, i+1, j);
    return (a[i] < a[k]) ? i : k;
}

void selectionsort_rec(int* a, int b, int e=0) {
    if(b == e) return;

    int key = min_i(a, e, b-1);
    if(key != e)
        swap(a[key], a[e]);

    selectionsort_rec(a, b, e+1);
}

int main() {
    int arr[] = {3,450,12,4,-1,0,24,95,123,0};
    for(int i = 0; i < 10; ++i) {
        cout << *(arr+i) << ' ';
    }
    cout << endl;
    selectionsort_rec(arr, 10);
    for(int i = 0; i < 10; ++i) {
        cout << *(arr+i) << ' ';
    }
    return 0;
}
