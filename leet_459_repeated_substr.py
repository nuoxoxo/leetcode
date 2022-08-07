class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        ls = s + s
        ls = ls[1: len(ls) - 1]
        return True if s in ls else False
