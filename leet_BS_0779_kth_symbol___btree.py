class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        res = 0
        L = 1
        R = 2 ** (n - 1)
        for _ in range(n - 1):
            mid = (R - L) // 2 + L
            if mid < k:
                L = mid + 1
                res ^= 1
            else:
                R = mid
        return res
