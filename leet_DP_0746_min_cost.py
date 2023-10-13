class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        size = len(cost)
        dp = [0] * (size + 1)
        for i in range(2, size + 1, 1):
            l = dp[i - 2] + cost[i - 2]
            r = dp[i - 1] + cost[i - 1]
            dp[i] = l if l < r else r
        return dp[size]
