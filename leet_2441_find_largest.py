class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        return [
            # Using_sorted,
            Using_set, # <- fast
        ][0](nums)

def Using_sorted(nums: List[int]) -> int:
    a = [-n for n in sorted(nums, reverse=True) if n > 0]
    for n in a:
        if n in nums:
            return -n
    return -1

def Using_set(nums: List[int]) -> int:
    s = set(nums)
    INF = -10**20
    res = INF
    for n in s:
        if n > 0 and -n in s and n > res:
            res = n
    if res == INF:
        return -1
    return res

