class Solution:
    def findLHS(self, nums: List[int]) -> int:
        mp = defaultdict(lambda: 0)
        res = 0
        for n in nums:
            mp[n] += 1
        for n in nums:
            if mp[n + 1] ^ 0:
                res = max(mp[n] + mp[n + 1], res)
        return res
