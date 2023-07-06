class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if target in nums:
            return 1
        isFound = False
        n = len(nums)
        res = 1e9
        for i in range(n):
            j = i + 1
            temp = nums[i]
            tooLong = False
            while j < n and temp < target:
                if j - i >= res:
                    tooLong = True
                    break
                temp += nums[j]
            if !tooLong and temp >= target and j - i < res:
                res = j - i
                isFound = True
        if !isFound:
            return 0
        return res
