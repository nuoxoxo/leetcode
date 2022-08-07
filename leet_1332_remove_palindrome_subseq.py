class Solution:
    def removePalindromeSub(self, s: str) -> int:
        i = 0
        j = len(s) - 1
        while i <= j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return 2
        return 1
