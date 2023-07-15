from collections import defaultdict
class Solution:
    def longestSubsequence(self, arr: List[int], diff: int) -> int:
        D = defaultdict(int)
        for n in arr:
            D[n] = D[n - diff] + 1
        return max(D.values())
