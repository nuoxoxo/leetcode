class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        if n == 3:
            return max(nums[1], nums[0] + nums[2])
        E = {}
        E[0] = nums[0]
        E[1] = nums[1]
        E[2] = max(nums[1], nums[0] + nums[2])
        i = 3
        while i < n:
            E[i] = max(nums[i] + E[i - 2], nums[i] + E[i - 3])
            i += 1
        return max(E[i - 1], E[i - 2])
