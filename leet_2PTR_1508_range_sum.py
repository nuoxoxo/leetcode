class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        a = []
        N = len(nums)
        MOD = 10 ** 9 + 7

        # O( n ^ 2 x logN)
        for L in range(N):
            windowSum = 0
            for R in range(L, N):
                windowSum += nums[R]
                a.append(windowSum)
        return sum(sorted(a)[left - 1 : right]) % MOD
