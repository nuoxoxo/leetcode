class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        N = len(nums)
        D = [0] * N
        res = []
        for i, n in enumerate(nums):
            if D[n - 1] == 1:
                res.append(n)
            else:
                D[n - 1] += 1
        return res
