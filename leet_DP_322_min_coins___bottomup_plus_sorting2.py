class Solution:
    def coinChange(self, coins: List[int], n: int) -> int:
        coins.sort()
        n += 1
        dp = [None] * n
        dp[0] = 0
        for i in range(1, n):
            dp[i] = n
            for c in coins:
                if i < c:
                    break
                dp[i] = min(dp[i], dp[i - c] + 1)
        return -1 if dp[n - 1] == n else dp[n - 1]
