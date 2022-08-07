class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        R = len(nums) - 1
        L = 0
        if R == 0:
            return True if nums[0] == target else False
        if nums[L] == target or nums[R] == target:
            return True
        while L < R and nums[L] == nums[L + 1]:
            L += 1
        while R > 0 and nums[R] == nums[R - 1]:
            R -= 1
        while L < R:
            mid = (L + R) // 2
            if nums[mid] == target:
                return True
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
        return False
