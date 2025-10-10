class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Inorder traversal (Left → Root → Right)
def inorder(p):
    if p:
        inorder(p.left)
        print(p.data, end=", ")
        inorder(p.right)


# Find Lowest Common Ancestor (LCA)
def lca(root, n1, n2):
    if root is None:
        return None
    if root.data == n1 or root.data == n2:
        return root

    left = lca(root.left, n1, n2)
    right = lca(root.right, n1, n2)

    if left and right:
        return root
    return left if left else right


# Build the tree manually
def build_sample_tree():
    root = Node(3)
    root.left = Node(6)
    root.right = Node(8)

    root.left.left = Node(2)
    root.left.right = Node(11)
    root.left.right.left = Node(9)
    root.left.right.right = Node(5)

    root.right.right = Node(13)
    root.right.right.left = Node(7)

    return root


if __name__ == "__main__":
    # Build tree and define queries
    root = build_sample_tree()
    queries = [(2, 5), (9, 5)]

    # Print the input setup
    print("Binary Tree Structure:")
    print("          3")
    print("        /   \\")
    print("       6     8")
    print("      / \\     \\")
    print("     2  11     13")
    print("        / \\    /")
    print("       9  5   7\n")

    print("Queries:")
    for n1, n2 in queries:
        print(f"  n1 = {n1}, n2 = {n2}")
    print()

    # Print inorder traversal
    print("In-Order Traversal: ", end="")
    inorder(root)
    print("\n")

    # Run LCA for each query
    for n1, n2 in queries:
        result = lca(root, n1, n2)
        if result:
            print(f"Lowest Common Ancestor of {n1} and {n2}: {result.data}")
        else:
            print(f"Nodes {n1} and/or {n2} not found.")