# Kruskal's Algorithm in Python

class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight


class DisjointSet:
    def __init__(self, n):
        # parent[i] = parent of i
        # initially each node is its own parent
        self.parent = [i for i in range(n)]

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            self.parent[py] = px  # merge y into x


class Graph:
    def __init__(self, verts):
        self.verts = verts
        self.edges = []

    # Add an edge to the graph
    def add_edge(self, src, dest, weight):
        self.edges.append(Edge(src, dest, weight))

    # Sort edges by weight
    def sort_edges(self):
        self.edges.sort(key=lambda e: e.weight)


def kruskal_mst(graph):
    graph.sort_edges()
    ds = DisjointSet(graph.verts)

    mst_edges = []
    total_weight = 0

    for edge in graph.edges:
        # Check if adding edge forms a cycle
        if ds.find(edge.src) != ds.find(edge.dest):
            ds.union(edge.src, edge.dest)
            mst_edges.append(edge)
            total_weight += edge.weight

    # Print MST edges and total weight
    print("The edges in the minimum spanning tree are:")
    for e in mst_edges:
        print(f"{{{e.src} {e.dest}}} W: {e.weight}")
    print(f"Total weight of tree is : {total_weight}")


if __name__ == "__main__":
    # Sample graph from your C++ code
    g = Graph(9)
    g.add_edge(0, 1, 7)
    g.add_edge(0, 7, 7)
    g.add_edge(1, 7, 11)
    g.add_edge(1, 2, 4)
    g.add_edge(7, 8, 4)
    g.add_edge(6, 7, 6)
    g.add_edge(2, 8, 3)
    g.add_edge(6, 8, 3)
    g.add_edge(2, 3, 2)
    g.add_edge(2, 5, 2)
    g.add_edge(5, 6, 1)
    g.add_edge(3, 5, 4)
    g.add_edge(3, 4, 1)
    g.add_edge(4, 5, 11)

    kruskal_mst(g)
