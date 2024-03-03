class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        N = len(nums)
        res = [0] * N
        l, r = 0, N - 1
        while l <= r:
            N -= 1
            L, R = abs(nums[l]), abs(nums[r])
            if L > R:
                res[N] = L * L
                l += 1
            else:
                res[N] = R * R
                r -= 1
        return res

