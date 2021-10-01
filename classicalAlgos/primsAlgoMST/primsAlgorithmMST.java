import java.util.*;
import java.lang.*;
import java.io.*;
 
class MinSpanTree {
    // Vertices in Graph
    private static final int V = 5;
 
    // Finds Vertex with Min Key
    int minKey(int key[], Boolean mstSet[])
    {
        // Initialize min value
        int min = Integer.MAX_VALUE, min_index = -1;
 
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
 
        return min_index;
    }
 
    // To print MST Stored
    void printMST(int parent[], int graph[][])
    {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++)
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
    }
 
    // To print MST through matrix representation
    void prim_MST(int graph[][])
    {
        // Array to store constructed MST
        int parent[] = new int[V];
 
        // Key values used to pick minimum weight edge in cut
        int key[] = new int[V];
 
        // To represent set of vertices included in MST
        Boolean mstSet[] = new Boolean[V];
 
        // Initialize all keys as INFINITE
        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }
 
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }
        printMST(parent, graph);
    }
 
    public static void main(String[] args)
    {
        MinSpanTree t = new MinSpanTree();
        int graph[][] = new int[rows][columns];
        for(int i=0; i<rows;i++)
         {            
            for(int j=0; j<columns;j++)
            {
                graph[i][j]=sc.nextInt();
            }
         }
 
        // Print the solution
        t.prim_MST(graph);
    }
}