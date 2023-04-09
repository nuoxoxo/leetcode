class Solution:

    def bs(self, nums: List[int], L: int, R: int, target: int) -> int:
        if L > R:
            return -1
        mid = (L + R) // 2
        if target == nums[mid]:
            return mid
        elif target < nums[mid]:
            return self.bs(nums, L, mid - 1, target)
        return self.bs(nums, mid + 1, R, target)

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n == 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        return self.bs(nums, 0, n - 1, target)
