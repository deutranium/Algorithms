# BFS python implementation to find path from the source vertex in a given graph
from collections import defaultdict 
class Graph: 
    # Graph initialization
	def __init__(self): 
		self.graph = defaultdict(list) 
	def addEdge(self,u,v): 
		self.graph[u].append(v)
	def BFS(self, s):
		visited = [0]*(len(self.graph)) # initializing all nodes as not visited
		queue = [] 
		queue.append(s) 
		visited[s] = 1 # initializing source as visited
		while queue: # traversing through all nodes reachable
			s = queue.pop(0) 
			print (s, end = "  ")
			for i in self.graph[s]: 
				if visited[i] == 0: 
					queue.append(i) 
					visited[i] = 1
# sample graph to run
g = Graph() 
g.addEdge(0, 1); 
g.addEdge(0, 2); 
g.addEdge(1, 2); 
g.addEdge(2, 3); 
g.BFS(2) 
 
