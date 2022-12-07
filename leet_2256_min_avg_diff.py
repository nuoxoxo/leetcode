class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 1:
            return 0
        s = 0
        for n in nums:
            s += n
        mn = 1e9
        res = -1
        l = 0
        r = s
        for i in range(0, size):
            l += nums[i]
            r -= nums[i]
            denom = size - i - 1
            if denom == 0:
                denom = 1
            diff = abs((l // (i + 1)) - (r // denom))
            if mn > diff:
                mn = diff
                res = i
        return res
