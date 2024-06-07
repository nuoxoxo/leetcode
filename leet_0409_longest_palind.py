class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = collections.Counter(s)
        res = 0
        mid = False
        for k, v in counter.items():
            if v % 2 == 1:
                mid = True
                res += v - 1
            else:
                res += v
        if mid:
            res += 1
        return res
