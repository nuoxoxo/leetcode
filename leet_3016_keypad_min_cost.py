class Solution:
    def minimumPushes(self, word: str) -> int:
        D = defaultdict(int)
        for c in word:
            D[c] += 1
        A = sorted(D.values(), reverse=True)
        return sum( [(i // 8 + 1) * cost for i, cost in enumerate(A)] )
        # initial soln
        """
        res = 0
        for i, cost in enumerate(A):
            res += cost * (i // 8 + 1)
        return res
        """
