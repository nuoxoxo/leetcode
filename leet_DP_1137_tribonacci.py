class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 2:
            return n
        f = [0 for _ in range(n + 1)]
        f[1] = 1
        f[2] = 1
        for i in range(3, n + 1):
            f[i] = f[i - 3] + f[i - 2] + f[i - 1]
        return f[n] 
