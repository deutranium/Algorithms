class Node:
    def _init_(self):
        self.children = [None] * 26
        self.isEnd = False


class Trie:
    def _init_(self):
        self.root = Node()

    def createNode(self):
        return Node()

    def _convertCharToIndex(self, ch):
        return ord(ch) - ord('a')

    def insert(self, word):
        # If key is not present, inserts it into trie, else just mark the word to be completed, by traversing the trie sequentially.
        currentNode = self.root
        for i in range(len(word)):
            index = self._convertCharToIndex(word[i])

            # if current character is not present
            if not currentNode.children[index]:
                currentNode.children[index] = self.createNode()
            currentNode = currentNode.children[index]

        # mark last node as completing a word
        currentNode.isEnd = True

    def search(self, word):
        current_node = self.root
        for i in range(len(word)):
            index = self._convertCharToIndex(word[i])

            # return false immediately if the current character is not present in the trie.
            if not current_node.children[index]:
                return False
            current_node = current_node.children[index]

        # even if the control reaches the end, then we have to check if a word ends here.
        return current_node.isEnd

# driver function here


def main():
    # take input of the number of words and the number of queries
    n = int(input("Enter the number of words: "))
    q = int(input("Enter the number of queries: "))

    t = Trie()
    print("Enter the words: ")
    while (n > 0):
        word = input().strip()
        t.insert(word)
        n -= 1

    print("Enter the queries: ")
    while (q > 0):
        word = input().strip()
        if t.search(word):
            print("YES")
        else:
            print("NO")
        q -= 1


# the main function to run the script
if __name__ == '__main__':
    # print("1")
    main()
