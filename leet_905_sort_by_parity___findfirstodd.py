class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pos = 0
        i = 0
        while i < n:
            if nums[i] % 2 == 0:
                nums[pos], nums[i] = nums[i], nums[pos]
                pos += 1
            i += 1
        return nums
