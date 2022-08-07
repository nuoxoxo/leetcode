class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 3:
            return 0
        res = 0
        for i in range(size - 2):
            dif = nums[i + 1] - nums[i]
            for j in range(i + 2, size):
                if nums[j] - nums[j - 1] != dif:
                    break
                else:
                    res += 1
        return res 
