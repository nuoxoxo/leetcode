class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        L, R = 0, 0
        total = sum(nums)
        for i in range(len(nums)):
            R = total - nums[i] - L
            if L == R:
                return i
            L += nums[i]
        return -1
