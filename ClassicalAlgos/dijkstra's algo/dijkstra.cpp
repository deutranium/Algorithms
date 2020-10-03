// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include<stdlib.h>
#include <stdio.h> 
#define V 9 

int min_dist(int dist[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void solution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V];

	bool sptSet[V];
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	
	dist[src] = 0; 

	
	for (int count = 0; count < V - 1; count++) { 
		int u = min_dist(dist, sptSet); 

		sptSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	solution(dist); 
} 

int main() 
{ 
    int graph[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j]=rand()%9;
        }
        
    }
    
	dijkstra(graph, 0); 

	return 0; 
} 
