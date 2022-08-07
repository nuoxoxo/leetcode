class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dp = [0] * n
        R = n - 1
        L = 0
        while L <= R:
            n -= 1
            if abs(nums[L]) < abs(nums[R]):
                dp[n] = nums[R] ** 2
                R -= 1
            else:
                dp[n] = nums[L] ** 2
                L += 1
        return dp
