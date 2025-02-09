class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        N = len(s)
        if N == k:
            return True # a set of 1-char panlinds
        if N < k:
            return False
        count = collections.Counter(s)
        odd = 0
        for v in count.values():
            odd += v % 2 == 1
        return odd <= k
