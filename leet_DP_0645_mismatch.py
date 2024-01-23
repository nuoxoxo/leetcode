class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        return [
            self.Solution_DP_2pass,
            self.Solution_Sorting_1pass,
        ][ random.randint(1,1) ]( nums )

    def Solution_Sorting_1pass(self, nums):
        print('/Solution_Sorting_1pass')
        nums.sort()
        res = [None, None]
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1] + 1:
                res[1] = nums[i - 1] + 1
            elif nums[i] == nums[i - 1]:
                res[0] = nums[i]
        if res[1] == None:
            # edge case : res[1] is None IIF the repeat is at either end of nums
            # conclusion: res[1] in [1, len(nums)], depends on where repeat is
            res[1] = 1 if nums[-1] == len(nums) else len(nums)
        return res

    def Solution_DP_2pass(self, nums):
        print('/Solution_DP_2pass')
        dp = [0] * len(nums)
        for n in nums:
            dp[n - 1] += 1
        res = [None, None]
        for i in range(len(nums)):
            if dp[i] == 2:
                res[0] = i + 1
            if dp[i] == 0:
                res[1] = i + 1
        return res

