class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n is 1:
            return True
        last = len(nums) - 1
        for i in range(last, -1, -1):
            if i + nums[i] >= last:
                last = i
        return last is 0
        
