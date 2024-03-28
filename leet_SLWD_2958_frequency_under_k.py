class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        N, l= len(nums), 0
        D = defaultdict(int)
        res = -1
        for r in range(N):
            D[ nums[ r ] ] += 1
            while D[ nums[ l ] ] > k:
                D[ nums[ l ] ] -= 1
                l += 1
            res = max(res, r - l + 1)
        return res
