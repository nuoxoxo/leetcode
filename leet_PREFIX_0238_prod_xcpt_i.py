class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)
        L, R = [0] * N, [0] * N
        L[0] = 1
        R[0] = 1
        for i in range(1, N):#, n in enumerate(nums[1:]):
            curr = nums[i - 1]
            L[i] = L[i - 1] * curr
        # for i in range(1, N):#, n in enumerate(nums[::-1][1:]):
            curr = nums[N - i]
            R[i] = R[i - 1] * curr
        res = [None] * N
        for i in range(N):
            res[i] = L[i] * R[N - 1 - i]
        return res

