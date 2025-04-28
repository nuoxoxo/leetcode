class Solution:
    def minOperations(self, nums: List[int]) -> int:
        N = len(nums)
        res = 0
        for i in range(2, N):
            if nums[i - 2] == 0:
                res += 1
                for j in range(i-2,i+1):
                    nums[j] ^= 1
        if nums[N - 1] == 0 or nums[N - 2] == 0:
            # print(nums)
            return -1
        return res
