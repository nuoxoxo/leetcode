class Solution:
    def findLHS(self, nums: List[int]) -> int:
        mp = {}
        res = 0
        for n in nums:
            if n in mp:
                mp[n] += 1
            else:
                mp[n] = 1
        for n in nums:
            if n in mp and n + 1 in mp:
                res = max(mp[n] + mp[n + 1], res)
        return res
