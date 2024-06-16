class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        # counter = collections.Counter(nums)
        res = 0
        nums.sort()
        for i, n in enumerate(nums):
            if i == len(nums) - 1:
                break
            if n >= nums[i + 1]:
                need = n - nums[i + 1] + 1
                nums[i + 1] += need
                res += need
        return res
