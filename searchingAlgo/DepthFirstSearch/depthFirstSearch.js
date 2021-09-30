// Graph class for the Algorithm
class Graph {
  constructor(v) {
    this.V = v;
    this.adj = Array(v);
    for (let i = 0; i < v; ++i) {
      this.adj[i] = [];
    }
  }

  addEdge(v, w) {
    this.adj[v].push(w);
  }

  DFSUtil(v, visited) {
    visited[v] = true;
    console.log(v + " ");
    let vList = this.adj[v];
    for (let n in vList) {
      if (!visited[n]) this.DFSUtil(n, visited);
    }
  }

  DFS(v) {
    let visited = new Array(this.V);
    this.DFSUtil(v, visited);
  }
}

function main() {
  let g = new Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  console.log(
    "The Following is Depth First Traversal " + "(Starting from vertex 2)"
  );
  g.DFS(2);
}

main();
