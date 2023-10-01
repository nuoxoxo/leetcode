class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        third = -1e9
        m = n
        for i in range(n - 1, -1, -1):
            if nums[i] < third:
                return True
            while m < n and nums[i] > nums[m]:
                third = nums[m]
                m += 1
            m -= 1
            nums[m] = nums[i]
        return False
