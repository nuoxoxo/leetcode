class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = nums[0]
        for i in range(len(nums)):
            nums[i] = max(nums[i], nums[i] + nums[i - 1])
            result = max(res, nums[i])
        return result
