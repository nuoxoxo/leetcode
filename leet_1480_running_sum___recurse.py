class Solution:
    def runningSum(self, nums: List[int], i = 1) -> List[int]:
        if i == len(nums):
            return nums
        nums[i] += nums[i - 1]
        return self.runningSum(nums, i + 1)
