class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 4:
            return n
        f = [i + 1 for i in range(n)]
        print(f)
        for i in range(3, n):
            f[i] = f[i - 1] + f[i - 2]
        print(f)
        return f[n - 1]

