#include<bits/stdc++.h>
using namespace std;

vector <int> helper(vector<int> g[],int S,bool visited[],vector<int>& v)
{
    v.push_back(S);
    //visited[S]=true;
    vector<int>::iterator i;
    for(i=g[S].begin();i!=g[S].end();i++)
    {
        if(visited[*i]==false)
        {
            visited[*i]=true;
            helper(g,*i,visited,v);
        }
    }
    return v;
}

vector <int> dfs(vector<int> g[], int N)
{
    bool* visited=new bool[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=false;
    }
    vector<int> v;
    
    for(int i=0;i<N;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            helper(g,i,visited,v);
        }
    }
    return v;

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
} 