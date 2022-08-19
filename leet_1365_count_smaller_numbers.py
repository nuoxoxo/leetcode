class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        for i in range(len(nums)):
            for n in nums:
                if n < nums[i]:
                    res[i] += 1
        return res
