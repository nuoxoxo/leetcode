class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        size = len(nums)
        mid = size // 2
        res = -1e9
        for i in range(mid):
            res = max(res, nums[i] + nums[size - i - 1])
        return res
