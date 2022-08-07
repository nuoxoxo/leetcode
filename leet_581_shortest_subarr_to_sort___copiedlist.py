class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        temp = nums[:]
        temp.sort()
        n = len(nums)
        mark = 0
        for i in range(n):
            if nums[i] != temp[i]:
                mark = i
                break
        for i in range(n - 1, -1, -1):
            if nums[i] != temp[i]:
                return i - mark + 1
        return mark
