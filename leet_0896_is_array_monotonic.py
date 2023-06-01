class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        size = len(nums)
        if size < 3:
            return True
        flag = 0
        for i in range(size - 1):
            if flag == 0 and nums[i] < nums[i + 1]:
                flag = 1
            elif flag == 0 and nums[i] > nums[i + 1]:
                flag= 2
            elif flag == 1 and nums[i] > nums[i + 1]:
                return False
            elif flag == 2 and nums[i] < nums[i + 1]:
                return False
        return True
