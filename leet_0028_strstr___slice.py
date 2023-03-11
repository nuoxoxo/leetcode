class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        L, R = len(haystack), len(needle)
        if R is 0:
            return 0
        if L is 0 or L < R:
            return -1
        i = 0
        while i < L - R + 1:
            if haystack[i : i + R] == needle:
                return i
            i += 1
        return -1


