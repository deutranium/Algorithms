#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

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
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w);

    void greedyColoring(vector<int> tokens);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

struct vertexDegree
{
    int v;
    int degree;
};

bool compareByDegree(const vertexDegree &x, const vertexDegree &y)
{
    return x.degree > y.degree;
}

void Graph::greedyColoring(vector<int> tokens)
{
    int maxin = 0;
    int *result = new int[V];

    if (tokens.size() == V)
    {
        for (int j = 0; j <= V; ++j)
        {
            if (tokens[j] >= 0)
                result[j] = tokens[j];
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (result[i] > maxin)
            maxin = result[i];
    }

    int max_degree = 0;

    vertexDegree arr[V];
    for (int i = 0; i < V; i++)
    {
        arr[i].v = i;
        arr[i].degree = adj[i].size();

        if (arr[i].degree >= max_degree)
        {
            max_degree = arr[i].degree;
        }
    }

    cout << "max degree: " << max_degree << endl;

    bool *colored = new bool[V];
    for (int c = 0; c < V; c++)
        colored[c] = false;

    for (int u = 0; u < V; u++)
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                colored[result[*i]] = true;

        int c;
        for (c = 0; c < V; c++)
            if (colored[c] == false)
                break;
        if (result[u] <= 0)
            result[u] = c;

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                colored[result[*i]] = false;
    }
    int maxout = 0;

    for (int i = 0; i < V; i++)
    {
        if (result[i] + 1 > maxout)
            maxout = result[i] + 1;
    }

    ofstream myfile2;
    myfile2.open("output.txt");
    myfile2 << abs(maxout - 1) << endl;
    cout << "# of colors: " << (maxout - 1) << endl;

    for (int u = 0; u < V; u++)
        myfile2 << result[u] << "  ";

    myfile2.close();
}

int main(int argc, char *argv[])
{
    ifstream myfile(argv[1]);
    string str;
    if (myfile.is_open())
    {

        getline(myfile, str);
        istringstream iss(str);
        vector<int> tokens((istream_iterator<int>(iss)), istream_iterator<int>());
        int V = tokens[0];
        int M = tokens[1];

        Graph g(V);
        while (getline(myfile, str))
        {

            istringstream iss(str);
            vector<int> tokens((istream_iterator<int>(iss)), istream_iterator<int>());
            int v = tokens[0];
            int w = tokens[1];
            if (tokens.size() == 2)
                g.addEdge(v - 1, w - 1);
            if (tokens.size() < 2 || (tokens.size() > 2 && tokens.size() != V))
            {
            }

            if (tokens.size() > 2)
            {
                g.greedyColoring(tokens);
            }
        }
    }

    else
        cout << " Unable to open your file";

    return 0;
}