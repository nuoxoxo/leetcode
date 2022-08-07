class Solution:
    def smallestRangeI(self, nums: List[int], K: int) -> int:
        diff = max(nums) - min(nums) - K * 2
        return diff if diff > 0 else 0
