class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        N = len(nums)
        for _ in range(N):
            for i in range(N - 1, 0, -1):
                if nums[i] < nums[i - 1] and nums[i].bit_count() == nums[i - 1].bit_count():
                    nums[i], nums[i - 1] = nums[i - 1], nums[i]
        for i in range(N - 1):
            if nums[i] > nums[i + 1]:
                return False
        return True
