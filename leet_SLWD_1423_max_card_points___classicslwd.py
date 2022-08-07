class Solution:
    def maxScore(self, p: List[int], k: int) -> int:
        best = sum(p[:k])
        temp = best
        n = len(p)
        for i in range(1, k + 1):
            temp += p[n - i]
            temp -= p[k - i]
            best = max(best, temp)
        return best
