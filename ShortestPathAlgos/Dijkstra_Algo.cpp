// GFG: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

/*Given a weighted, undirected and connected graph of V vertices and
 an adjacency list adj where adj[i] is a list of lists containing two integers 
 where the first integer of each list j denotes there is edge between i and j ,
 second integers corresponds to the weight of that  edge .
 You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S.
You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 */

#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>> st;
    st.insert({0,S});
    
    vector<int> dist(V, 1e9);
    
    dist[S] = 0;
    
    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        
        st.erase(it);
        
        for(auto x: adj[node])
        {
            int adjNode = x[0];
            int adjWt = x[1];
            
            if(dis + adjWt < dist[adjNode])
            {
                if(dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                
                dist[adjNode] = dis + adjWt;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

// Time Complexity: O(ElogV)


