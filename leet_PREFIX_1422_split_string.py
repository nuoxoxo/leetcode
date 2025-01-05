class Solution:
    def maxScore(self, s: str) -> int:
        ones = 0
        for c in s:
            ones += 1 if c == '1' else 0
        res = 0
        z = 0 #if s[0] == '0' else 1
        for i in range( len(s) - 1 ):# ,c in enumerate(s):
            c = s[i]
            if c == '0':
                z += 1
            if c == '1':
                ones -= 1
            res = max(res, ones + z)
        return res
