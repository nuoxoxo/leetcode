class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        s = set(nums)
        N = len(s)
        return N - 1 if 0 in s else N
