import  java.util.*;

class greedyGraphColoring{

    //function to return adjaceny list for graph for specified number of vertices
    static ArrayList<ArrayList<Integer>> graphCreate(int v){
        ArrayList<ArrayList<Integer> > graph= new ArrayList<ArrayList<Integer> >(v);
        for (int i=0;i<v;i++){
            graph.add(new ArrayList<Integer>());
        }
        return graph;
    }

    //function to create adjacency list representation of graph
    static void addEdge( ArrayList<ArrayList<Integer>> graph , int a , int b){
        graph.get(a).add(b);
        graph.get(b).add(a);
    }

    //greedy algorithm to solve graph coloring problem
    static String[] greedyGraphColoring(ArrayList<ArrayList<Integer>> graph,String[] colors){

        int n= graph.size();
        int color=colors.length;

        //Creating a list vertices to assign colours to
        int[] vertices=new int[graph.size()];
        for(int i=0;i<n;i++){
            vertices[i]=-1;
        }
    
        
        for(int ii=0;ii<n;ii++){


            ArrayList<Integer> neighbours=graph.get(ii);
            ArrayList<Integer> forbidden= new ArrayList<Integer>();
            for(int i=0;i<neighbours.size();i++){
                if(vertices[neighbours.get(i)]!=-1){
                    forbidden.add(vertices[neighbours.get(i)]);
                }
            }

            //Assigning color to vertice 
            for(int i=0;i<color;i++){
                if(!forbidden.contains(i)){
                    vertices[ii]=i;
                    break;
                }
            }

        

        }

        //Mapping the colors
        String[] verticeColors= new String[n];
        for(int i=0;i<n;i++){
            verticeColors[i]= colors[vertices[i]];
        }
        return verticeColors;
    }

    
    
    public static void main(String[] args)
    {
        // Creating a graph with 5 vertices
        int vertices = 5;
        ArrayList<ArrayList<Integer>> adj = graphCreate(vertices);
        String [] colors =new String[] {"red", "chocolate", "darkorange", "moccasin", "gold"};

  
        // Adding edges one by one.
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 4);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 4);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
       
        String [] verticeColors= greedyGraphColoring(adj,colors);

        // Printing vertices and their respective colors

        System.out.println("Node : Color");
        for(int i=0;i<adj.size();i++){
            String s= i+ ":" +verticeColors[i];
            System.out.println(s);
        }


    }
}


