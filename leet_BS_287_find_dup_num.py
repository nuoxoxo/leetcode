class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if n == 2:
            return nums[0]
        i = 1
        j = n - 2
        n //= 2
        while i != j and i < n and j > n:
            if nums[i] == nums[i - 1]:
                return nums[i]
            if nums[j] == nums[j + 1]:
                return nums[j]
            i += 1
            j -= 1
        return nums[i]
