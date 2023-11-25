class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        res = []
        L, R = 0, 0
        for n in nums:
            R += n
        for i in range(len(nums)):
            L += nums[i]
            # print(nums[i], L, R)
            res.append(nums[i] * (2 * i - len(nums) + 1) - L + R)
            R -= nums[i]
        return res

        """
        - got a rough idea :: for any index 'i' in a sorted array, its absodiff
            = 
        nums[i] - num[i] 
        nums[i] - num[i - 1] + 
        nums[i] - num[i - 2] + 
            ... 
        nums[i] - nums[0] + 
            ...
        nums[i] + nums[i]
        nums[i + 1] - nums[i] + 
        nums[i + 2] - nums[i] +
            ...
        nums[n - 1] - nums[i]
            -->
        pt1 = nums[i] * (i + 1) - sum( nums[:i + 1] )
        pt2 = sum( nums[i:] ) - nums[i] * (n - i)) 
        p1 + p2 = R - L + (i + 1 - n + i) * nums[i]
            -->
        nums[i] * (2 * i - n + 1) - Lsum + Rsum
        """

