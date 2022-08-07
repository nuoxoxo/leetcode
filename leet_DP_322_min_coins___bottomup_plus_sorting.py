class Solution:
    def coinChange(self, coins: List[int], n: int) -> int:
        n += 1
        dp = [n] * n
        dp[0] = 0
        coins.sort()
        for i in range(1, n):
            for c in coins:
                if i < c:
                    break
                dp[i] = min(dp[i], dp[i - c] + 1)
        return -1 if dp[n - 1] == n else dp[n - 1]
