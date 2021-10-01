#include <bits/stdc++.h>
using namespace std;

const int V = 9;
vector<pair<int, int>> adj[V]; //adj[i] stores pairs {vert,cost}
int dist[V];

void make_Graph()
{
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {7, 8, 7}, {6, 7, 1}, {2, 8, 2}, {6, 8, 6}, {5, 6, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}};
    for (auto &vec : edges)
    {
        int sour = vec[0], dest = vec[1], cost = vec[2];
        adj[sour].push_back({dest, cost});
        adj[dest].push_back({sour, cost});
    }
}

void dijkstra(int sour)
{
    for (int x = 0; x < V; x++)
    {
        dist[x] = INT_MAX;
    }
    dist[sour] = 0;
    set<pair<int, int>> st; //Stores pairs {distance,vertex}
    st.insert({dist[sour], sour});
    while (!st.empty())
    {
        auto pa = *st.begin();
        st.erase(st.begin());
        int u = pa.second;
        int cost_u = pa.first;
        if (cost_u > dist[u])
            continue;
        for (auto &neb : adj[u])
        {
            int v = neb.first;
            int weight = neb.second;
            if (dist[v] > dist[u] + weight)
            {
                st.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                st.insert({dist[v], v});
            }
        }
    }
}

int main()
{
    make_Graph();
    dijkstra(0);
    for(int x=0;x<V;x++){
        cout<<dist[x]<<" ";
    }cout<<endl;
    return 0;
}