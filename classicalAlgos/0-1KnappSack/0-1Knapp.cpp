#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

void solve()
{
    int n, w;
    cin >> n;
    cin >> w;
    int dp[n + 1][w];
    vector<int> wt(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> wt[i];
    int ma = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (wt[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][max(0, j - wt[i])] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
            ma = max(ma, dp[i][j]);
        }
    cout << ma << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
