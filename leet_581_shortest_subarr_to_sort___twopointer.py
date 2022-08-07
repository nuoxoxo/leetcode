class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        prev = nums[0]
        tail = 0
        for i in range(1, n):
            if prev > nums[i]:
                tail = i
            else:
                prev = nums[i]
        if tail == 0:
            return 0
        prev = nums[n - 1]
        head = n - 1
        for i in range(n - 2, -1, -1):
            if nums[i] > prev:
                head = i
            else:
                prev = nums[i]
        return tail - head + 1

"""
[2,6,4,8,10,9,15]
[1,2,3,4]
[1]
[1,3,2,4,5]
[1,3,2,2,2]
[2,1]
"""
