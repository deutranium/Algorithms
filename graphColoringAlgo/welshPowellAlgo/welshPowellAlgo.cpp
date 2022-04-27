#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>


struct Vertex {
    char id; // An upper-case character representing the node label
    int degree;
    std::vector<char> adj; // a list of all the adjacent nodes: with their letters
    int label; // *color*

    /** Add edge to undirected graph
     * \param node Another node to connect to
     * \return Void
     */
    void addEdge(Vertex& node)
    {
        adj.push_back(node.id);
        degree++;

        node.adj.push_back(id);
        node.degree++;
    }

    /** Check whether current vertex is connected to the target vertex
     * \param target Vertex to check against
     * \return True if they're connected, false otherwise
     */
    bool isConnected(const Vertex& target)
    {
        return std::find(adj.begin(), adj.end(), target.id) != adj.end();
    }
};

struct Graph {
    // adding/deleting elements is more efficient
    std::list<Vertex> vertices;

    void addVertex(Vertex node)
    {
        vertices.push_back(node);
    }
    void addVertex(Vertex&& node)
    {
        vertices.push_back(node);
    }
};

void welshPowell(Graph& graph)
{
    // sort vertices in descending order
    graph.vertices.sort([](const Vertex& a, const Vertex& b) -> bool {
        return a.degree > b.degree;
    });

    std::list<Vertex*> unlabeledVertices;
    for (auto& vertex: graph.vertices) {
        unlabeledVertices.push_back(&vertex);
    }

    int label = 1;
    for (auto iter = unlabeledVertices.begin(); iter != unlabeledVertices.end(); ++label) {
        (*iter)->label = label;

        /** a set of all vertices with the same color, all operations has a
         * constant time of O(1) on average
         */
        std::unordered_set<Vertex*> currentLabelVertices;
        currentLabelVertices.insert(*iter);

        // check if we can label any other vertex with the current color
        auto nestedIter = iter; nestedIter++;
        for (; nestedIter != unlabeledVertices.end(); ) {
            // checking current vertex against any other colored vertex
            if (std::none_of(currentLabelVertices.begin(), currentLabelVertices.end(),
                [=](const Vertex* v){ return (*nestedIter)->isConnected(*v); })) {
                (*nestedIter)->label = label;
                currentLabelVertices.insert(*nestedIter);

                nestedIter = unlabeledVertices.erase(nestedIter);
            }
            else {
                nestedIter++;
            }
        }

        iter = unlabeledVertices.erase(iter);
    }
}

int main()
{
    Graph graph {{
        {'A', 3, {'B', 'C', 'D'}},
        {'B', 2, {'A', 'D'}},
        {'C', 2, {'A', 'D'}},
        {'D', 3, {'A', 'B', 'C'}}
    }};

    welshPowell(graph);

    for (const auto& v: graph.vertices) {
        std::cout << v.id << "-->" << v.label << '\n';
    }
    return 0;
}
