class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        dp = [0] * (n + 1)
        # dp[0] = 0
        # dp[1] = 0
        dp[2] = 1 * 1
        for i in range(3, n + 1, 1):
            for j in range(1, i // 2 + 1, 1):
                dp[i] = max(dp[i], dp[i - j] * j, (i - j) * j)
        return dp[n]
