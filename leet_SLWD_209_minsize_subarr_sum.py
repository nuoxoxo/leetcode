class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if target in nums:
            return 1
        yes = False
        res = 1e9
        fast = 0
        slow = 0
        add = 0
        while fast < len(nums):
            add += nums[fast]
            while add >= target:
                yes = True
                res = min(res, fast - slow + 1)
                add -= nums[slow]
                slow += 1
            fast += 1
        if yes:
            return res
        return 0
