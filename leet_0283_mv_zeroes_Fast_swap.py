class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        x = 0
        i = 0
        while i < len(nums):
            if nums[i] != 0:
                if i != x:
                    nums[i], nums[x] = nums[x], nums[i]
                x += 1
            i += 1
