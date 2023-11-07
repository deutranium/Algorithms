#Use disjoint union set structure to check if two nodes belong to same connected component
class Union_Set:
    def __init__(self,numberOfNodes):
        self.numberOfNodes = numberOfNodes
        #Initially Each node represents it's own connected component of size 1
        self.parent = [i for i in range(numberOfNodes)]
        self.setSize = [1 for i in range(numberOfNodes)]
    def find_parent(self,nodeV):
        if self.parent[nodeV] == nodeV:
            return nodeV
        self.parent[nodeV] = self.find_parent(self.parent[nodeV])
        return self.parent[nodeV]
    #Returns true if two nodes does not belong to the same connected component
    def Merge_Sets(self,nodeA,nodeB):
        nodeA = self.find_parent(nodeA)
        nodeB = self.find_parent(nodeB)
        if nodeA != nodeB:
            if self.setSize[nodeA] > self.setSize[nodeB]:
                self.parent[nodeB] = nodeA
                self.setSize[nodeA] += self.setSize[nodeB]
                print(nodeA, nodeB)
            else:
                self.parent[nodeA] = nodeB
                self.setSize[nodeB] += self.setSize[nodeA]
                print(nodeB, nodeA)
            return True
        return False

class Graph:
    def __init__(self,numberOfNodes):
        self.numberOfNodes = numberOfNodes
        self.graph = []
    def add_edge(self,nodeA,nodeB,edgeWeight):
        #Add an undirected weighted edge between node A and node B
        self.graph.append([nodeA,nodeB,edgeWeight])
    def Krsukals(self):
        self.graph = sorted(self.graph,key=lambda edge : edge[2])
        dsu = Union_Set(self.numberOfNodes)
        numberOfEdges = len(self.graph)
        minMstWeight = 0
        mstEdges = []
        for edge in self.graph:
            #Adds this edge to list of edges in minimum spanning tree if these nodes belong to different connected components
            if dsu.Merge_Sets(edge[0],edge[1]):
                mstEdges.append(edge)
                minMstWeight += edge[2]
        print(minMstWeight)
        #Prints all the edges that belong to the miniumum spanning tree
        for edge in mstEdges:
            print("{" , edge[0], ",", edge[1],"} W:",edge[2])

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
g.Krsukals()
