class Solution:
    def strStr(self, hay: str, nee: str) -> int:
        h = len(hay)
        n = len(nee)
        if n is 0:
            return 0
        if h is 0 or n > h:
            return -1
        i = 0
        while i < h - n + 1:
            if hay[i : i + n] == nee:
                return i
            i += 1
        return -1
