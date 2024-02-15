class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        curr = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < curr:
                res = nums[i] + curr
            curr += nums[i]
        return res if res != 0 else -1

