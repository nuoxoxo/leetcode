class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        size = len(s)
        if size is 0:
            return True
        if len(t) is 0:
            return False
        i = 0
        for c in t:
            if s[i] == c:
                i += 1
            if size == i:
                return True
        return False
