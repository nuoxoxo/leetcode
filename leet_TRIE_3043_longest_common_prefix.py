class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        trie = Trie()
        for n in arr1:
            trie.add(str(n))
        res = 0
        for n in arr2:
            dist = trie.lookup(str(n))
            res = max(res, dist)
        return res

class Node:
    def __init__(self):
        self.edges = {}
class Trie:
    def __init__(self):
        self.root = Node()
    def add(self, s):
        node = self.root
        for c in s:
            if c not in node.edges:
                node.edges[c] = Node()
            node = node.edges[c]
    def lookup(self, s):
        node = self.root
        res = 0
        for c in s:
            if c not in node.edges:
                break
            res += 1
            node = node.edges[c]
        return res

