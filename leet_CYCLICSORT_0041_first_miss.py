class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        N = len(nums)
        i = 0
        while i < N:
            if 0 < nums[i] < N + 1 and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
                #   Strange : below line not working
                # nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
            else:
                i += 1
        for i in range(N):
            if nums[i] != i + 1:
                return i + 1
        return N + 1
