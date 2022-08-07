class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        run = 0
        n = len(nums)
        res = [0] * n
        for i in range(n):
            run += nums[i]
            res[i] = run
        return res
