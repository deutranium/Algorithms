// https : //codeforces.com/contest/427/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9 + 7;
stack<int> stk;
bool vis1[100005], vis2[100005];
int rep[100005];
vector<int> adj[100005], rev[100005];
vector<pair<int, int>> edges;
void trav(int n)
{
    vis1[n] = true;
    for (auto i : adj[n])
        if (!vis1[i])
            trav(i);
    stk.push(n);
}
void trav2(int n, int id)
{
    // cout<<"\t"<<id<<",";
    vis2[n] = true;
    for (auto i : rev[n])
        if (!vis2[i])
            trav2(i, id);
    rep[n] = id;
    // cout<<rep[n]<<" ";
}

void solve()
{
    int n;
    cin >> n;
    int cost[n+1];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    int m;
    cin >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
        edges.push_back({x, y});
    }
    for (int i = 1; i <= n; i++)
        if (!vis1[i])
            trav(i);
    int id = 1;
    while (!stk.empty())
    {
        int t = stk.top();
        stk.pop();
        if (!vis2[t])
        {
            trav2(t, id);
            id++;
        }
    }
    // for (int i = 1; i <= n; i++)cout << rep[i] << " ";cout<<endl;
    vector<int> minnie(id, INT_MAX), c(id+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (minnie[rep[i]] == cost[i])
            c[rep[i]]++;
        else
        {
            if (cost[i] < minnie[rep[i]])
            {
                c[rep[i]] = 1;
                minnie[rep[i]] = cost[i];
            }
            else
                continue;
        }
    }
    ll ans = 1, ans2 = 0;
    // cout << endl;
    for (int i = 1; i < id ; i++)
    {
        // cout << c[i] <<","<<minnie[i]<<" ";
        ans = (ans * c[i]) % mod;
        ans2 += minnie[i];
    }
    cout << ans2 << " " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
