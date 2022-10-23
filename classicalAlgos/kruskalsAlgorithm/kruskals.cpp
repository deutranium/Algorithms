#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vii;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

#define ll long long int
#define ld long double
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (ll)((x).size())
#define fr first
#define sc second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define in(x) cin >> x
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define no "NO" << endl
#define yes "YES" << endl
#define sp " "
#define speed                   \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);              \
    cout.tie(NULL);

int npower(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * x);
        n /= 2;
        x = (x * x);
    }
    return res;
}
int modpow(int x, int n, int M)
{
    x = x % M;
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * x) % M;
        }
        n /= 2;
        x = (x * x) % M;
    }
    return res;
}
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

// Alias for edge and respective weight <<src, dest>, weight>
typedef pair<pi, int> Edge;

// Disjoint set structure <node id, subset id>
typedef pair<int, int> Disjoint;

// Creating Graph Struct
/*
 * *IF BEING USED: clean() FUNCTION MUST BE USED WHEN DONE*
 *
 */
struct Graph
{
    int inSet(int setI);
    int verts, Edg_num;
    Edge *edges;
    Disjoint *sets;

    int n = 0;

    // Constructors
    Graph()
    {
        this->verts = 4;
        this->Edg_num = 5;
        this->edges = new Edge[this->Edg_num];
        this->sets = new Disjoint[this->verts];
        for (int i = 0; i < this->verts; i++)
        {
            this->sets[i].first = i;
            this->sets[i].second = i;
        }

        add_Edge(0, 1, 5);
        add_Edge(0, 2, 3);
        add_Edge(0, 3, 2);
        add_Edge(1, 3, 7);
        add_Edge(2, 3, 2);
    }

    Graph(int verts, int edges)
    {
        this->verts = verts;
        this->Edg_num = edges;
        this->edges = new Edge[edges];
        this->sets = new Disjoint[this->verts];
        for (int i = 0; i < this->verts; i++)
        {
            this->sets[i].second = i;
        }
    }

    //*****Helpers*****//

    // Adds edge to graph, if attempting to add more edges than declared, edges wont be set
    void add_Edge(int src, int dest, int w)
    {
        // If more edges than declared on creation
        if (n >= Edg_num)
        {
            cout << "Can not add edge: {" << src << " " << dest << "}, too many edges" << endl;
            return;
        }

        // Add edge and update
        this->edges[n] = {{src, dest}, w};
        n++;
    }

    // Utilizing selection sort to sort graph edges by weight
    void sort(int size, Edge *edge)
    {
        int min;

        for (int i = 0; i < size - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (edge[j].second < edge[min].second)
                {
                    min = j;
                }
            }
            Edge t = edge[i];
            edge[i] = edge[min];
            edge[min] = t;
        }
    }

    // Cleans up memory of graph
    void clean()
    {
        delete[] edges;
        edges = NULL;
    }
};

// Function Declarations
void mst(Graph g);

int main()
{
    // Making default test graph

    Graph x = Graph(9, 14);
    x.add_Edge(0, 1, 7);
    x.add_Edge(0, 7, 7);
    x.add_Edge(1, 7, 11);
    x.add_Edge(1, 2, 4);
    x.add_Edge(7, 8, 4);
    x.add_Edge(6, 7, 6);
    x.add_Edge(2, 8, 3);
    x.add_Edge(6, 8, 3);
    x.add_Edge(2, 3, 2);
    x.add_Edge(2, 5, 2);
    x.add_Edge(5, 6, 1);
    x.add_Edge(3, 5, 4);
    x.add_Edge(3, 4, 1);
    x.add_Edge(4, 5, 11);
    mst(x);

    x.clean();
}

// Kruskal's Algorithm
void mst(Graph g)
{
    // Sorting by weight first
    g.sort(g.Edg_num, g.edges);

    // MST and index
    int treeEdge = 0;
    Edge *tree = new Edge[g.verts];

    // Making trees and checking cycles
    int count = 0;
    while (count < g.Edg_num)
    {
        int sourceSet, destinationSet;

        // Find if vertex subset has been merged from original subset
        sourceSet = g.inSet(g.edges[count].first.first);
        destinationSet = g.inSet(g.edges[count].first.second);

        // If not in same subset (no cycle)
        if (sourceSet != destinationSet)
        {
            // Add edge to minimum spanning tree
            tree[treeEdge++] = g.edges[count];

            // Merge subsets
            g.sets[destinationSet].second = g.sets[sourceSet].second;
        }
        count++;
    }

    // Print MST
    int totalW = 0;
    cout << "The edges in the minimum spanning tree are:" << endl;
    for (int i = 0; i < g.verts - 1; i++)
    {
        cout << "{" << tree[i].first.first << " " << tree[i].first.second << "} W: " << tree[i].second << endl;
        totalW += tree[i].second;
    }
    cout << "Total weight of tree is : " << totalW << endl;
}

// Determine subset location of vertex
int Graph::inSet(int setI)
{
    if (setI == sets[setI].second)
    {
        return setI;
    }
    else
    {
        return inSet(sets[setI].second);
    }
}