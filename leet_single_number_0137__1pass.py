class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        nums.sort()
        if nums[0] ^ nums[1]:
            return nums[0]
        i = 0
        while i < len(nums) - 2:
            if nums[i] ^ nums[i + 1] and nums[i + 1] ^ nums[i + 2]:
                break
            i += 1
        return nums[i + 1]
        
