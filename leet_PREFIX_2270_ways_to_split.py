class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        N = len(nums)
        p = [0] * N # prefix sums
        running = 0
        for i,n in enumerate(nums):
            running += n
            p[i] = running
        return sum([p[i] >= p[N-1] - p[i] for i in range(N-1)])
