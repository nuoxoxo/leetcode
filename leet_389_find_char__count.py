class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        if len(s) == 0:
            return t[0]
        for c in t:
            if s.count(c) != t.count(c):
                break
        return c
