class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        return [
            # Brute,
            Trie_solution,
        ][0](dictionary, sentence)

# Trie solution
def Trie_solution(dictionary: List[str], sentence: str) -> str:
    trie = Trie(dictionary)
    res = []
    words = sentence.split(' ')
    for w in words:
        candidate = trie.find(w)
        res.append(candidate)
    return ' '.join(res)

class TrieNode:
    def __init__(self):
        self.edges = dict()
        self.isend = False

class Trie:
    def __init__(self, dictionary):
        self.root = TrieNode()
        for word in dictionary:
            self.insert(word)

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.edges:
                node.edges[char] = TrieNode()
            node = node.edges[char]
        node.isend = True

    def find(self, word):
        node = self.root
        res = ''
        for char in word:
            if char not in node.edges:
                break
            res += char
            node = node.edges[char]
            if node.isend:
                return res
        return word

# initial solution
def Brute(dictionary: List[str], sentence: str) -> str:
    words = sentence.split(' ')
    for i, w in enumerate(words):
        shortest = 1e9
        candidate = ''
        for key in dictionary:
            if w.startswith(key) and shortest > len(key):
                shortest = len(key)
                candidate = key
        if candidate != '':
            words[i] = candidate
    return ' '.join(words)

