class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2) or set(word1) != set(word2):
            return False
        n = len(word1)
        D, E = defaultdict(int), defaultdict(int)
        for i in range(n):
            D[word1[i]] += 1
            E[word2[i]] += 1
        return sorted(D.values()) == sorted(E.values())
