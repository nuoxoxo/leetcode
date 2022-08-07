class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        size = len(nums)
        mx = max(nums)
        dp = [0 for _ in range(mx + 1)]
        for n in nums:
            dp[n] += n
        for i in range(2, mx + 1):
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2])
        return max(dp)
