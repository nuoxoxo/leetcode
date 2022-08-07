class Solution:
    def search(self, nums: List[int], target: int) -> int:
        R = len(nums) - 1
        L = 0
        if target == nums[L]:
            return L
        if target == nums[R]:
            return R
        while L < R:
            mid = (L + R) // 2
            if nums[mid] == target:
                return mid
            if nums[0] < nums[mid]:
                if nums[0] < target < nums[mid]:
                    R = mid
                else:
                    L = mid + 1
            else:
                if nums[mid] < target < nums[-1]:
                    L = mid + 1
                else:
                    R = mid
        return -1
