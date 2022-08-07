class Solution:
    def tribonacci(self, n: int) -> int:
        if n is 0:
            return n
        if n < 3:
            return 1
        g = [None] * (1 + n)
        g[0] = 0
        g[1] = g[2] = 1
        i = 3
        while i < n + 1:
            g[i] = g[i - 3] + g[i - 2] + g[i - 1]
            i += 1
        return g[n]
