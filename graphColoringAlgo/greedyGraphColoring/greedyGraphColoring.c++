/*
	 							Greedy Graph Coloring Algorithm
								

The greedy approach to solving the graph coloring problem can be using at most x+1 colors if the maximum degree of a vertex is x.
The greedy approach does not guarantee that the minimum number of colors are used but, 
surely, the maximum x+1 colors are used where x is the maximum degree of any vertex in the given graph.

We will color the current vertex with the least-numbered color. 
After that, we will check if the currently assigned least color has been used previously for any adjacent vertex of the current vertex or not.
If it is not used then we can continue the process to the next vertex else, we will assign the next color.


Let us see the pseudo-code for the same.

Pseudo code can be:
1. Color the first vertex of the graph with the first color.
2. Repeat the below step for the remaining vertices. 
	2.1.Color the current vertex with the minimum numbered color. 
	2.2.Make sure that the selected minimum number color has not been used previously for any adjacent vertex of the current vertex.


Time Complexity: O(V^2 + E) worst case
Space Complexity: O(1) as no extra space is used
*/


// A C++ program to implement greedy graph coloring algorithm


#include <bits/stdc++.h>
using namespace std;

// A class for undirected graph
class Graph {
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists

    public:
        // Constructor and destructor
        Graph(int V) { 
            this->V = V; 
            adj = new list<int>[V];
        }
        ~Graph() {
            delete [] adj;
        }

        // function to add an edge to the graph
        void addEdge(int v, int w);

        // Prints greedy coloring of the vertices
        void greedyColoring();
};

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// Assigns colors (0 indexed) to all vertices and prints the colors for respective vertices
void Graph::greedyColoring() {
	int result[V];

	// Assign the first color to first vertex
	result[0] = 0;

	// Initialize remaining vertices as unassigned(-1)
	for (int u = 1; u < V; u++) {
		result[u] = -1; // no color is assigned to u
    }

	// A temporary array to store the available colors.
	// True value of available[c] would mean that the color "c" is
	// assigned to one of its adjacent vertices
	bool available[V];
	for (int cr = 0; cr < V; cr++) {
		available[cr] = false;
    }

	// Assign colors to remaining vertices
	for (int u = 1; u < V; u++) {
		// Process all adjacent vertices and flag their colors as unavailable
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			if (result[*i] != -1)
				available[result[*i]] = true;
        }

		// Find the first available color
		int cr;
		for (cr = 0; cr < V; cr++) {
			if (available[cr] == false)
				break;
        }

		result[u] = cr; // Assign the vertice that color

		// Reset the values back to false for the next iteration
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			if (result[*i] != -1)
				available[result[*i]] = false;
        }
	}

	// print the result
	for (int u = 0; u < V; u++) {
		cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

// Main function with initialization of 2 graphs ans their respective results
int main() {
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	cout << "Coloring of graph 1 \n";
	g1.greedyColoring();

	Graph g2(5);
	g2.addEdge(0, 1);
	g2.addEdge(0, 2);
	g2.addEdge(1, 2);
	g2.addEdge(1, 4);
	g2.addEdge(2, 4);
	g2.addEdge(4, 3);
	cout << "\nColoring of graph 2 \n";
	g2.greedyColoring();

	return 0;
}
