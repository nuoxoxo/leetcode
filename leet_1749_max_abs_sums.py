class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        def kadane(A):
            curr,res = 0,0
            for n in A:
                if curr < 0:
                    curr = 0
                curr += n
                res = max(curr, res)
            return res
        return max(kadane(nums), kadane([-_ for _ in nums]))
            
