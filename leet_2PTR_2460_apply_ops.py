class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        N = len(nums)
        for i in range(N - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        idx = 0
        for i in range(N):
            if nums[i] != 0:
                nums[i], nums[idx] = nums[idx], nums[i]
                idx += 1
        return nums
