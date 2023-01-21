class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        res = -1
        mini = 1e9 # keep record of the lowest so far
        for n in nums:
            mini = min(n, mini)
            if n > mini:
                res = max(res, n - mini)
        return res
