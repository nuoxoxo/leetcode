class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        N = len(nums)
        f0 = 0
        tt = 0
        for i, n in enumerate(nums):
            f0 += n * i
            tt += n
        res = f0
        fi = f0
        for i in range(1, N):
            fi = fi + tt - N * nums[N - i]
            res = max(fi, res)
        return res
"""
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25

F(1) = (1 * 4) + (2 * 3) + (3 * 2) + (0 * 6)
        f(i-1) + sum(nums) - N * nums[N - i] 👈 Thats the formula
        = 0 + 4 + 6 + 6 = 16

F(2) = (2 * 4) + (3 * 3) + (0 * 2) + (1 * 6) = 0 + 6 + 8 + 9 = 23
F(3) = (3 * 4) + (0 * 3) + (1 * 2) + (2 * 6) = 0 + 2 + 12 + 12 = 26

👆

# Mathy shifts
#   ---> notice that for each i we 
#       1) Added a (4+3+2+6) which is the sum(nums)
#       2) Subtract N*nums[N-i]
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (1 * 4) + (2 * 3) + (3 * 2) + (0 * 6) = 0 + 4 + 6 + 6 = 16
F(2) = (2 * 4) + (3 * 3) + (0 * 2) + (1 * 6) = 0 + 6 + 8 + 9 = 23
F(3) = (3 * 4) + (0 * 3) + (1 * 2) + (2 * 6) = 0 + 2 + 12 + 12 = 26

👆

# original
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
"""
