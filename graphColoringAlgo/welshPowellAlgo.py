import random
import itertools
import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

def greedyColoringAlgo(network, colors):
    nodes = list(network.nodes()) 
    nodes.sort(reverse=True)
    for node in nodes:
        dict_neighbors = dict(network[node])
        nodes_neighbors = list(dict_neighbors.keys())
        
        forbidden_colors = []
        for neighbor in nodes_neighbors:
            if len(network.nodes.data()[neighbor].keys()) == 0: 
                continue
            else:
                forbidden_color = network.nodes.data()[neighbor]
                forbidden_color = forbidden_color['color']                
                forbidden_colors.append(forbidden_color)
        for color in colors:
            if color in forbidden_colors:
                continue
            else:
                network.nodes[node]['color'] = color
                break

## Create a graph, and an array of colors that has atleast (d+1) colors 
## Where d is the highest degree of all the vertices.

G = nx.Graph()
G.add_nodes_from([1, 6])
G.add_edges_from([(1, 2), (1, 3),(1,4),(1,5),(1,6)])
G.add_edges_from([(2,3),(2, 4), (2,5),(2,6)])
G.add_edges_from([(3, 4), (3,5),(3,6)])
G.add_edges_from([(4,6)])
colors = ["red", "chocolate", "darkorange", "moccasin", "gold"]
greedyColoringAlgo(G,colors)

## Visualization of graph can be done by the code below
colors_nodes = [data['color'] for v, data in G.nodes(data=True)]
plt.figure(1,figsize=(9,9))  
nx.draw(G, node_color=colors_nodes, with_labels=True)
plt.show  