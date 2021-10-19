/**
 * Creates a Graph with [size] nodes
 * @param init constructor for adding the edges of the nodes delegated to the instances
 */
class Graph(size: Int, init: Graph.() -> Unit) {
    val adjacency: Array<MutableList<Int>> = Array(size) { ArrayList() }

    init { init() }

    fun addEdge(node: Int, to: Int) = adjacency[node].add(to)
}

/**
 * Prints the route taken when exploring the [graph] starting from [current]
 * @param searched an array of booleans relating to whether the relating nodes have been searched
 */
fun depthFirstSearch(graph: Graph, current: Int, searched: Array<Boolean> = Array(graph.adjacency.size) { false }) {
    if(!searched[current]) {
        searched[current] = true
        print("$current ")
        for (next in graph.adjacency[current]) {
            depthFirstSearch(graph, next, searched)
        }
    }
}

fun main() {
    val graph = Graph(4) {
        addEdge(0, 1)
        addEdge(0, 2)
        addEdge(1, 2)
        addEdge(2, 0)
        addEdge(2, 3)
        addEdge(3, 3)
    }
    println("Following is Depth First Traversal " + "(Starting from vertex 2)")
    depthFirstSearch(graph, 2)
}