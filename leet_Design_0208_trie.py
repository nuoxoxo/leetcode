class TrieNode:
    def __init__(self):
        self.branch = defaultdict(TrieNode)
        self.ended = False

class Trie:

    def __init__(self):
        self.node = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.node
        for c in word:
            if c not in cur.branch:
                cur.branch[c] = TrieNode()
            cur = cur.branch[c]
        cur.ended = True

    def search(self, word: str) -> bool:
        cur = self.node
        for c in word:
            if c not in cur.branch:
                return False
            cur = cur.branch[c]
        return cur.ended

    def startsWith(self, prefix: str) -> bool:
        cur = self.node
        for c in prefix:
            if c not in cur.branch:
                return False
            cur = cur.branch[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
