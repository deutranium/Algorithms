using System;
class MST {
    static int V = 5;
    static int minKey(int[] key, bool[] mstSet)
    {
        int min = int.MaxValue, min_index = -1;
 
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
 
        return min_index;
    }
    //Print MST
    static void printMST(int[] parent, int[, ] graph)
    {
        Console.WriteLine("Edge \tWeight");
        for (int i = 1; i < V; i++)
            Console.WriteLine(parent[i] + " - " + i + "\t" + graph[i, parent[i]]);
    }
    //MST Function
    static void primMST(int[, ] graph)
    {
        int[] parent = new int[V];
        int[] key = new int[V];
        bool[] mstSet = new bool[V];
        for (int i = 0; i < V; i++) {
            key[i] = int.MaxValue;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
 
            // Add the picked vertex
            // to the MST Set
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (graph[u, v] != 0 && mstSet[v] == false
                    && graph[u, v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u, v];
                }
        }
        printMST(parent, graph);
    }
 
    // Driver Code
    public static void Main()
    {
        int[, ] graph = new int[, ] { { 0, 3, 0, 8, 0 },
                                      { 3, 0, 3, 8, 5 },
                                      { 0, 3, 0, 0, 7 },
                                      { 8, 8, 0, 0, 9 },
                                      { 0, 5, 7, 9, 0 } };
        primMST(graph);
    }
