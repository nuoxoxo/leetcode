class Solution:
    def titleToNumber(self, C: str) -> int:
        res = 0
        for c in C:
            res = ord(c) - 64 + res * 26
        return res
