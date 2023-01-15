#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define ppb pop_back
#define sp <<" "<<
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define all(c) c.begin(), c.end()
#define INF 1e18
#define mod 1000000007
#define pi (3.141592653589)

typedef pair<ll,pair<ll,ll>>ppl;
typedef pair<ll,ll>pl; 
typedef vector<ll> vll;

const int M = 1e9+7;
const int N = 1e5+5;
vector<int>g[N];
vector<int>vis;
void toposort_dfs(int source, stack<int>&st){
    vis[source] = true;
    for(auto child:g[source]){
        if(vis[child]) continue;
        toposort_dfs(child,st);
    }
    st.push(source);
}
void solve(int p)
{
    //taking input for the graph
    int n,m;        //m = number of nodes, m = number of edges
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    vis.resize(n+1,false);
    for(int i = 0;i<n;i++){
        if(vis[i]) continue;
        toposort_dfs(i,st);
    }
    vector<int>v;
    while(!st.emtpy()){
        v.push_back(st.top());
        st.pop();
    }
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return;
}
int main()
{
    int t = 1;
    cin>>t;
    int p = 1;
    while (t--)
    {
        solve(p++);
    }
}