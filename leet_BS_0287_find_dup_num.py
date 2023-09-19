class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        L = len(nums)
        if L == 2:
            return nums[0]
        i = 1
        j = L - 2
        mid = L // 2
        while i != j and i < mid and j > mid:
            if nums[i] == nums[i - 1]:
                return nums[i]
            if nums[j] == nums[j + 1]:
                return nums[j]
            i += 1
            j -= 1
        return nums[i]
