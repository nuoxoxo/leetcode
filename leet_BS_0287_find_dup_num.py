class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        return [
            # self.Naive,
            self.Two_pointers,
        ][0](nums)

    def Two_pointers(self, nums: List[int]) -> int:
        N = len(nums)
        if N < 3:
            return nums[0]
        nums.sort()
        l, r = 1, N - 2
        mid = N // 2
        while l != r and l < mid and r > mid:
            if nums[l - 1] == nums[l]:
                return nums[l]
            if nums[r] == nums[r + 1]:
                return nums[r]
            l += 1
            r -= 1
        return nums[mid]

    def Naive(self, nums: List[int]) -> int:
        nums.sort()
        res = None
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                res = nums[i]
                break
        return res

