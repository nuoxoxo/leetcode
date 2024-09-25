class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        res = []
        for w in words:
            trie.add(w)
        for w in words:
            res.append( trie.count(w) )
        return res

class Node:
    def __init__(self):
        self.edges = {}
        self.count = 0 # NEW
class Trie:
    def __init__(self):
        self.root = Node()
    def add(self, s):
        node = self.root
        for c in s:
            if c not in node.edges:
                node.edges[c] = Node()
            node = node.edges[c]
            node.count += 1 # NEW
    def count(self, s):
        res = 0
        node = self.root
        for c in s:
            node = node.edges[c]
            res += node.count
        return res
    """
    def lookup(self, s):
        node = self.root
        res = 0
        for c in s:
            if c not in node.edges:
                break
            res += 1
            node = node.edges[c]
        return res
    """
