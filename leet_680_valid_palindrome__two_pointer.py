class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        i = 0
        j = n - 1
        while i < j:
            if s[i] != s[j]:
                L = s[i + 1: j + 1]
                R = s[i: j]
                return L == L[::-1] or R == R[::-1]
            i += 1
            j -= 1
        return True
