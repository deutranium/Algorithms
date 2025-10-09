// BFS java implementation to find path from the source vertex in a given graph
import java.io.*; 
import java.util.*; 
class Graph 
{ 
	private int V; 
	private LinkedList<Integer> adj[]; 
	Graph(int v) // initialize graph
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	}  
	void addEdge(int v,int w) // add edges
	{ 
		adj[v].add(w); 
	} 
	void BFS(int s) // algorithm
	{ 
		boolean visited[] = new boolean[V]; 
		LinkedList<Integer> queue = new LinkedList<Integer>(); 
		visited[s]=true; 
		queue.add(s); 

		while (queue.size() > 0) 
		{  
			s = queue.poll(); 
			System.out.print(s+" "); 
			Iterator<Integer> i = adj[s].listIterator(); 
			while (i.hasNext()) 
			{ 
				int n = i.next(); 
				if (!visited[n]) 
				{ 
					visited[n] = true; 
					queue.add(n); 
				} 
			} 
		} 
	} 
	public static void main(String args[]) // sample graph
	{ 
		Graph g = new Graph(4); 

		g.addEdge(0, 1); 
		g.addEdge(0, 2); 
		g.addEdge(1, 2); 
		g.addEdge(2, 3); 
		g.BFS(2); 
	} 
} 
