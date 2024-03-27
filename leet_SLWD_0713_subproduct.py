class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k < 2:
            return 0
        count = 0
        fast = 0
        slow = 0
        prod = 1
        while fast < len(nums):
            prod *= nums[fast]
            while prod > k - 1:
                prod //= nums[slow]
                slow += 1
            count += fast - slow + 1
            fast += 1
        return count
