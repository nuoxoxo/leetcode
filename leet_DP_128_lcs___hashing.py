class Solution:
    def longestConsecutive(self, n: List[int]) -> int:
        L = len(n)
        if L < 2:
            return L
        E = [1] * L
        n.sort()
        for i in range(1, L):
            t = n[i] - n[i - 1]
            if t < 2:
                E[i] = E[i - 1] + t
        return max(E)
