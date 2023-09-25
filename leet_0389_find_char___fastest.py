class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res = ord(t[-1])
        i = 0
        while i < len(s):
            res += ord(t[i])
            res -= ord(s[i])
            i += 1
        return chr(res)
