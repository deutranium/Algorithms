#include<iostream>
#include <list>

using namespace std;


class Graph //create a Graph node
{
    int V;
    list<int> *adj;
    void DFS_visit(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) //constructor
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS_visit(int v, bool visited[])
{

    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end();i++)
        {
            if (!visited[*i])
            DFS_visit(*i, visited);
        }
}


void Graph::DFS(int v)
{
    // Marking all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;


  DFS_visit(v, visited);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal \n";
    int n;
    cin>>n;
    g.DFS(n);

    return 0;
}
//INPUT: 5
//OUTPUT:
//Following is Depth First Traversal 
//5 2 0 1 3
