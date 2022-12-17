class Solution:
    def rob(self, nums: List[int]) -> int:
        s = len(nums)
        if s == 1: return nums[0]
        if s == 2: return max(nums[0], nums[1])
        if s == 3: return max(nums[1], nums[2] + nums[0])
        E = {}
        E[0] = nums[0]
        E[1] = nums[1]
        E[2] = max(nums[1], nums[0] + nums[2])
        i = 3
        while i < s:
            E[i] = max(nums[i] + E[i - 2], nums[i] + E[i - 3])
            i += 1
        return max(E[i - 1], E[i - 2])
