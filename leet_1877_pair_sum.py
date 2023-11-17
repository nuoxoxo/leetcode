class Solution:
    def minPairSum(self, nums: List[int]) -> int:

        # new soln

        nums.sort()
        res = 0
        l, r = 0, len(nums) - 1
        while l < r:
            res = max(res, nums[l] + nums[r])
            l += 1
            r -= 1
        return res

        # old soln

        # nums.sort()
        # size = len(nums)
        # mid = size // 2
        # res = -1e9
        # for i in range(mid):
        #     res = max(res, nums[i] + nums[size - i - 1])
        # return res
