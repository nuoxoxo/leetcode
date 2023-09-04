class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        L, R = 0, len(nums) - 1
        res = 0
        nums.sort()
        while L < R:
            if nums[L] + nums[R] < target:
                res += R - L
                L += 1
            else :
                R -= 1
        return res
