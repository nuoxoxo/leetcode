class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 1:
            return 1 if nums[0] < target else 0
        L, R = 0, len(nums) - 1
        while L <= R:
            M = (R - L) // 2 + L
            Mv = nums[M]
            if Mv == target:
                return M
            elif Mv < target:
                L = M + 1
            else:
                R = M - 1
        return L
