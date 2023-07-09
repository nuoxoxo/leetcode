class Solution:
    def minOperations(self, nums: List[int]) -> int:
        i = 0
        res = 0
        while i < len(nums) - 1:
            i += 1
            if nums[i - 1] < nums[i]:
                continue
            needed = nums[i - 1] - nums[i] + 1
            res += needed
            nums[i] = nums[i -1] + 1
        return res
