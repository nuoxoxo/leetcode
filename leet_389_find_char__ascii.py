class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ss = sorted(s)
        tt = sorted(t)
        res = ord(tt[-1])
        i = 0
        while i < len(s):
            res += ord(tt[i])
            res -= ord(ss[i])
            i += 1
        return chr(res)
