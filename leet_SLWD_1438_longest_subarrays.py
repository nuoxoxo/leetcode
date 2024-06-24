class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        from sortedcontainers import SortedList
        SL = SortedList()
        res = 0
        L = 0
        for R, n in enumerate(nums):
            SL.add(n)
            while L < R and limit < abs(SL[-1] - SL[0]):
                SL.remove(nums[L])
                L += 1
            res = max(res, R - L + 1)
        return res

