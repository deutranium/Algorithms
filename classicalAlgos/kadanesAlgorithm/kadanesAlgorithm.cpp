#include <bits/stdc++.h>
#define endl '\n'  // pls remove while debugging
#define ll long long int
using namespace std;

int kadane(vector<int> a) { 
    int res = INT32_MIN;
    int cur = 0;
    int n = a.size();
    for (int i =0; i<n; i++) {
        cur += a[i];
        res = max(res, cur);
        cur = max(cur, 0);
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> a(n);
    for (int i =0; i<n; i++) cin>>a[i];
    
    cout<<kadane(a)<<endl;
    return 0;
}