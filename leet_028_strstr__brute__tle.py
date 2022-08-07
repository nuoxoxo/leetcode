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
            j = 0
            while i + j < h and j < n and hay[i + j] == nee[j]:
                j += 1
            if j is n:
                return i
            i += 1
        return -1
