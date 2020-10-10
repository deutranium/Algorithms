/*
    C++ program for Fibonacci Search
*/
#include <bits/stdc++.h>
using namespace std;

/*
    Function to return the index of x in arr
    Time Complexity : O(logn)
*/
int fibMonaccianSearch(int arr[], int x, int n)
{
    int l = 0;
    int r = 1;
    int sum = l + r;

    while (sum < n) {

        l = r;
        r = sum;
        sum = l + r;

    }

    int offset = -1;

    while (sum > 1) {

        int i = min(offset + l, n - 1);

        if (arr[i] < x)
        {
            sum = r;
            r = l;
            l = sum - r;
            offset = i;
        }

        else if (arr[i] > x)
        {
            sum = r;
            r = r - l;
            l = sum - r;
        }

        else return i;

    }

    if (l and arr[offset + 1] == x) return offset + 1;

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 7, 9, 13, 17, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;

    cout << "Index of " << x << " in arr is " << fibMonaccianSearch(arr, x, n) << "\n";

    return 0;
}
