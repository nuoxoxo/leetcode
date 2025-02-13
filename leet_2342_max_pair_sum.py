class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        res = -1
        D = {}
        for i,n in enumerate(nums):
            digsum = 0
            while n > 0:
                digsum += n % 10
                n //= 10
            if digsum not in D:
                D[digsum] = nums[i]
            else:
                res = max(res, nums[i] + D[digsum])
                D[digsum] = max(D[digsum], nums[i]) # take 43 when prev is 7
        return res

