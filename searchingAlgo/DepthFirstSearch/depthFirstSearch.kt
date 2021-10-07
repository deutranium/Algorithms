import java.util.*
import kotlin.collections.HashSet

class NodeNotFoundException : Throwable("Node was not found")

class Graph<V>(var value: V, var nodes: MutableSet<Graph<V>> = HashSet(), init: Graph<V>.() -> Unit = {}) {

    init { init() }

    fun add(value: V, nodes: MutableSet<Graph<V>> = HashSet(), init: Graph<V>.() -> Unit = {}) {
        this.nodes.add(Graph(value, nodes, init))
    }

    override fun toString() = value.toString()
}

fun <V> depthFirstSearch(root: Graph<V>, searchValue: V): Result<List<Graph<V>>> {

    val map = HashMap<Graph<V>, Graph<V>>()
    val toSearch = Stack<Graph<V>>().apply { push(root) }

    while (toSearch.isNotEmpty()) {

        val currentNode = toSearch.pop()

        if (currentNode.value == searchValue)
            return Result.success(mapToRoute(root, currentNode, map))

        currentNode.nodes.forEach {
            if (!map.containsKey(it)) {
                map[it] = currentNode
                toSearch.push(it)
            }
        }
    }
    return Result.failure(NodeNotFoundException())
}

fun <V> mapToRoute(root: Graph<V>, to: Graph<V>, path: Map<Graph<V>, Graph<V>>): List<Graph<V>> {

    var position: Graph<V> = to
    val result: MutableList<Graph<V>> = ArrayList()

    while (position != root) {
        result.add(position)
        position = path[position]!!
    }

    result.add(root)
    return result.reversed()
}

fun main() {

    val graph = Graph(1) {
        add(10) {
            add(2) {
                add(4)
            }
            add(4)
        }
        add(2) {
            add(7)
        }
    }

    val result = depthFirstSearch(graph, 4)

    result.fold(
        onSuccess = {
            println(it.joinToString(separator = " -> "))
        },
        onFailure = {
            println("No node with this value was found")
        }
    )
}