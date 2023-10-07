// GFG: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

/*Algorithm : Dijkstra's algorithm is a graph traversal and shortest path-finding algorithm. It finds the shortest path between a starting node and all other nodes in a weighted graph, where each edge has a non-negative weight. 
 
 Logic: he algorithm maintains a set of visited nodes and uses a priority queue to explore nodes in order of their current distance from the start node. It iteratively selects the node with the smallest distance, updates the distances to its neighbors if a shorter path is found, and continues until all nodes have been visited or the destination node is reached.
 
 */

#include<bits/stdc++.h>
using namespace std;

// Function to implement Dijkstra Algorithm
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>> st; // set to store the distance and node pair
    st.insert({0,S}); // insert the source node with distance 0
    
    vector<int> dist(V, 1e9); // vector to store the distance of each node from source
    
    dist[S] = 0; // distance of source node from itself is 0
    
    while(!st.empty())
    {
        // find the node with minimum distance
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        
        st.erase(it);
        

        // traverse the adjacency list of the node
        for(auto x: adj[node])
        {
            int adjNode = x[0];
            int adjWt = x[1];
            
            // if the distance of adjacent node is greater than the distance of current node + weight of edge between them
            if(dis + adjWt < dist[adjNode])
            {
                // if the adjacent node is already visited then erase it from the set
                if(dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                
                // update the distance of adjacent node
                dist[adjNode] = dis + adjWt;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    // return the distance vector
    return dist;
}

int main()
{
    // Test case 1 (same as before)
    int V1 = 5; // Number of vertices for Test case 1
    int E1 = 7; // Number of edges for Test case 1
    int S1 = 0; // Source node for Test case 1

    // Define the adjacency list for Test case 1
    vector<vector<int>> adj1[V1];

    // Add edges to the adjacency list for Test case 1
    adj1[0].push_back({1, 2});
    adj1[0].push_back({2, 4});
    adj1[1].push_back({2, 1});
    adj1[1].push_back({3, 7});
    adj1[2].push_back({3, 3});
    adj1[2].push_back({4, 5});
    adj1[3].push_back({4, 2});

    // Call the dijkstra function for Test case 1
    vector<int> res1 = dijkstra(V1, adj1, S1);

    // Print the result for Test case 1
    cout << "Test case 1 result: ";
    for (int i = 0; i < V1; i++)
        cout << res1[i] << " ";
    cout << endl;

    // Test case 2
    int V2 = 3; // Number of vertices for Test case 2
    int E2 = 3; // Number of edges for Test case 2
    int S2 = 1; // Source node for Test case 2

    // Define the adjacency list for Test case 2
    vector<vector<int>> adj2[V2];

    // Add edges to the adjacency list for Test case 2
    adj2[0].push_back({1, 2});
    adj2[1].push_back({2, 3});
    adj2[2].push_back({0, 1});

    // Call the dijkstra function for Test case 2
    vector<int> res2 = dijkstra(V2, adj2, S2);

    // Print the result for Test case 2
    cout << "Test case 2 result: ";
    for (int i = 0; i < V2; i++)
        cout << res2[i] << " ";
    cout << endl;

    return 0;
}



// Time and Space Complexity for Best Average and Worst cases:
// Time Complexity: O(ElogV)
// Time Complexity: O(V)


