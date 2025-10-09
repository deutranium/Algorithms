# Trie Node class
class TrieNode:
    def __init__(self):
        # Each node has up to 26 children (a-z)
        self.sons = [None] * 26
        # Maximum weight stored at this node
        self.wt = 0

# Insert a string with weight into the trie
def insert(root, s, w):
    node = root
    for ch in s:
        index = ord(ch) - ord('a')
        if node.sons[index] is None:
            node.sons[index] = TrieNode()
        node = node.sons[index]
        node.wt = max(node.wt, w)

# Search for string in trie and return max weight of its prefix
def search(root, s):
    node = root
    ans = -1
    for ch in s:
        index = ord(ch) - ord('a')
        if node.sons[index] is None:
            return -1
        node = node.sons[index]
        ans = node.wt
    return ans

def solve():
    # Sample input
    n, q = 4, 3  # 4 words, 3 queries
    words = [("apple", 5), ("app", 3), ("banana", 7), ("bat", 4)]
    queries = ["app", "apple", "batman"]

    print("Words with weights:")
    for word, w in words:
        print(f"{word} -> {w}")

    root = TrieNode()
    for s, wt in words:
        insert(root, s, wt)

    print("\nQueries and results:")
    for s in queries:
        result = search(root, s)
        print(f"{s} -> {result}")

if __name__ == "__main__":
    solve()
