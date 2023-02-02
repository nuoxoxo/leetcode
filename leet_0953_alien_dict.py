class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        E = { c : i for i, c in enumerate(order) }
        size = len(words) - 1
        for i in range(size):
            L, R = words[i], words[i + 1]
            Lz = len(L)
            Rz = len(R)
            for j in range(len(L)):
                if j == Rz:
                    return False
                if L[j] != R[j]:
                    if E[ L[j] ] > E[ R[j] ]:
                        return False
                    break
        return True 
