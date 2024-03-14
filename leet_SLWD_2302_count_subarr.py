class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        return [
            self.Sliding_window,
        ][ 0 ]( nums, k )

    def Sliding_window(self, nums: List[int], k: int) -> int:
        N = len(nums)
        res = 0
        curr = 0
        l = 0
        for r in range(N):
            curr += nums[r]
            while curr * (r - l + 1) >= k:
                curr -= nums[l]
                l += 1
            res += r - l + 1
        return res

