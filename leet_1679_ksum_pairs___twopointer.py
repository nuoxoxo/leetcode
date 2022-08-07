class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        L = 0
        R = len(nums) - 1
        res = 0
        nums.sort()
        while L < R and nums[L] < k:
            a, b = nums[L], nums[R]
            if a + b < k:
                L += 1
            elif a + b > k:
                R -= 1
            else:
                res += 1
                L += 1
                R -= 1
        return res
