class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        tt = 1
        L = 0
        R = 0
        while R < len(nums):
            if nums[R] == 0:
                tt -= 1
            if tt < 0:
                print(tt)
                if nums[L] == 0:
                    tt += 1
                L += 1
            R += 1
        return R - L - 1

