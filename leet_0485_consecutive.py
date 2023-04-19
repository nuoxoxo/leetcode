class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        r = 0
        t = 0
        for n in nums:
            if n == 0:
                r = max(r, t)
                t = 0
            else:
                t += 1
        return max(r, t)

