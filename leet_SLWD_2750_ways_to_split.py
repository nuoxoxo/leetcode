class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        return [
            self.Sliding_window,
        ][0](nums)
        
    def Sliding_window(self, nums: List[int]) -> int:
        MOD = int(1e9 + 7)
        N = len(nums)
        res = 0
        l = 0
        for r in range(N):
            if nums[r] == 1:
                res %= MOD
                res = res * (r - l + 1) if res > 0 else 1
                l = r + 1
        return res % MOD
