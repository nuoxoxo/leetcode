class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        tt = 1
        L = 0
        for R in range(len(nums)):
            if nums[R] == 0:
                tt -= 1
            if tt < 0:
                if nums[L] == 0:
                    tt += 1
                L += 1
        return len(nums) - 1 - L

