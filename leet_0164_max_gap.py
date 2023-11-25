class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        size = len(nums)
        res = 0
        if size < 2:
            return res
        nums.sort()
        for i in range(1, len(nums)):
            res = max(res, nums[i] - nums[i - 1])
        return res
