class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        nums.sort()
        i = 0
        j = len(nums) - 1
        while i < j:
            if nums[i] != nums[i + 1] or nums[j] != nums[j - 1]:
                return False
            i += 2
            j -= 2
        return True
                
