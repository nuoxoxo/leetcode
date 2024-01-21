class Solution:
    def rob(self, nums: List[int]) -> int:
        return [
            self.Solution_Constant_Space,
            self.Solution_Topdown_DP,
            self.Solution_Classic_DP,
        ][ random.randint(0,2) ]( nums )

    def Solution_Constant_Space(self, nums) -> int:
        print('/Solution_Constant_Space')
        if len(nums) < 3: return max (nums)
        res = 0 # curr
        prevprev = 0
        for n in nums:
            res, prevprev = max(prevprev + n, res), res
            # or use a temp for res 👆
        return res

    def Solution_Classic_DP(self, nums) -> int:
        print('/Solution_Classic_DP')
        size = len(nums)
        if size < 3:
            return max(nums)
        dp = [0] * (size)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        dp[2] = max(nums[2] + nums[0], nums[1])
        for i in range(3, size):
            dp[i] = max( dp[i - 1], dp[i - 2] + nums[i] )
        return dp[-1]

    def Solution_Topdown_DP(self, nums) -> int:
        print('/Solution_Topdown_DP')
        memo = [-1] * len(nums) # attemt: to fix TLE
        def dp(nums, i) -> int:
            if i < 0:
                return 0
            if memo[i] != -1:
                return memo[i]
            curr = max(dp(nums, i - 1), nums[i] + dp(nums, i - 2))
            memo[i] = curr
            return curr
        return dp( nums, len(nums) - 1 )

