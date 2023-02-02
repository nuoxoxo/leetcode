class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        E = {}
        for i in range(len(order)):
            E[order[i]] = i
        for i in range(len(words) - 1):
            s1, s2 = words[i], words[i + 1]
            size_1 = len(s1)
            size_2 = len(s2)
            for j in range(size_1):
                if j == size_2:
                    return False
                if s1[j] != s2[j]:
                    if E[s1[j]] > E[s2[j]]:
                        return False
                    break
        return True

