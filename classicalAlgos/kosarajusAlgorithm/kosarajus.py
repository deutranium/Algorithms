from sys import setrecursionlimit
setrecursionlimit(10**6)

MOD = 10**9 + 7

# DFS on original graph to fill nodes in order of finishing time
def dfs1(node, adj, visited, stack):
    visited[node] = True
    for nei in adj[node]:
        if not visited[nei]:
            dfs1(nei, adj, visited, stack)
    stack.append(node)


# DFS on reversed graph to assign SCC IDs
def dfs2(node, rev, visited, rep, scc_id):
    visited[node] = True
    rep[node] = scc_id
    for nei in rev[node]:
        if not visited[nei]:
            dfs2(nei, rev, visited, rep, scc_id)


def solve():
    # Sample input
    n = 5
    costs = [0, 2, 3, 1, 2, 3]
    m = 6
    edges = [(1, 2), (2, 3), (3, 1), (3, 4), (4, 5), (5, 4)]

    print("Input Graph:")
    print(f"Number of nodes: {n}")
    print(f"Node costs: {costs[1:]}")
    print(f"Edges: {edges}\n")

    # Build adjacency list and reversed adjacency list
    adj = [[] for _ in range(n + 1)]
    rev = [[] for _ in range(n + 1)]
    for x, y in edges:
        adj[x].append(y)
        rev[y].append(x)

    visited = [False] * (n + 1)
    stack = []

    # Fill stack with nodes in order of finishing time
    for i in range(1, n + 1):
        if not visited[i]:
            dfs1(i, adj, visited, stack)

    visited = [False] * (n + 1)
    rep = [0] * (n + 1)
    scc_id = 0

    # Assign SCC IDs using DFS on reversed graph
    while stack:
        node = stack.pop()
        if not visited[node]:
            scc_id += 1
            dfs2(node, rev, visited, rep, scc_id)

    # Compute minimum cost and number of nodes with that cost in each SCC
    min_cost = [float('inf')] * (scc_id + 1)
    count = [0] * (scc_id + 1)
    for i in range(1, n + 1):
        scc = rep[i]
        if costs[i] < min_cost[scc]:
            min_cost[scc] = costs[i]
            count[scc] = 1
        elif costs[i] == min_cost[scc]:
            count[scc] += 1

    # Compute total minimum cost and total number of ways
    total_cost = sum(min_cost[1:])
    total_ways = 1
    for c in count[1:]:
        total_ways = (total_ways * c) % MOD

    print(f"Output:\nMinimum total cost: {total_cost}")
    print(f"Number of ways: {total_ways}")


if __name__ == "__main__":
    solve()
