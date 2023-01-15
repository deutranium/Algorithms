#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void greedyColoring()
    {
        int result[V];
        result[0] = 0;
        for (int u = 1; u < V; u++)
            result[u] = -1;

        bool available[V];
        for (int cr = 0; cr < V; cr++)
            available[cr] = false;

        for (int u = 1; u < V; u++)
        {
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = true;

            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr] == false)
                    break;

            result[u] = cr;

            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = false;
        }

        for (int u = 0; u < V; u++)
            cout << "Vertex " << u << " ---> Color "
                 << result[u] << endl;
    }
};

int main()
{
    Graph g1(7);
    g1.addEdge(0, 4);
    g1.addEdge(0, 5);
    g1.addEdge(0, 6);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 5);
    g1.addEdge(5, 6);
    cout<<"Coloured graph : \n";
    g1.greedyColoring();

    return 0;
}
