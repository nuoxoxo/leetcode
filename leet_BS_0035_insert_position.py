class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums) - 1
        while L <= R:
            i = (R - L) // 2 + L
            if nums[i] == target:
                return i
            elif nums[i] < target:
                L = i + 1
            else:
                R = i - 1
        return L
