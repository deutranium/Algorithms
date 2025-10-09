class Graph:
    def __init__(self, v):
        # Initialize graph with v vertices and an empty adjacency list
        self.V = v
        self.adj = [[] for _ in range(v)]

    def add_edge(self, v, w):
        # Add an edge from vertex v to vertex w
        self.adj[v].append(w)

    def dfs_util(self, v, visited):
        # Recursive helper function for DFS starting from vertex v
        visited[v] = True
        print(v, end=" ")
        for n in self.adj[v]:
            if not visited[n]:
                self.dfs_util(n, visited)

    def dfs(self, v):
        # Perform DFS traversal starting from vertex v
        visited = [False] * self.V
        self.dfs_util(v, visited)


def main():
    # Create graph and add edges
    g = Graph(4)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)

    print("The Following is Depth First Traversal (Starting from vertex 2):")
    g.dfs(2)  # Start DFS from vertex 2
    print()


if __name__ == "__main__":
    main()
