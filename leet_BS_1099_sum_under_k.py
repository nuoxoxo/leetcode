class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        res = -1
        if len(nums) < 2:
            return res
        nums.sort()
        if nums[0] >= k or nums[0] + nums[1] >= k:
            return res
        l, r = 0, len(nums) - 1
        res = -1
        if nums[0] > k: return -1
        while nums[r] > k:
            r -= 1
        while l < r:
            temp = nums[l] + nums[r]
            if temp < k:
                res = max(res, nums[l] + nums[r])
                l += 1
            else:
                r -= 1
        return res
