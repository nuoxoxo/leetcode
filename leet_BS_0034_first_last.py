class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        size = len(nums)
        r = size - 1
        l = 0
        while l <= r:
            mid = (r - l) // 2 + l
            if nums[mid] == target:
                l, r = mid, mid
                while l > -1 and nums[l] == target:
                    l -= 1
                while r < size and nums[r] == target:
                    r += 1
                return [l + 1, r - 1]
            if nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return [-1, -1]

