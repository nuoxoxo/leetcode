class Solution:
    def findMin(self, nums: List[int]) -> int:
        R = len(nums)
        L = 0
        if R == 1 or nums[0] < nums[-1]:
            return nums[0]
        R -= 1
        while L < R:
            mdp = L + (R - L) // 2
            if nums[mdp] >= nums[0] and nums[mdp] >= nums[-1]:
                L = mdp + 1
            else:
                R = mdp
        return nums[L]
