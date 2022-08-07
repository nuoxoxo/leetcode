class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        L = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ' and L > 0:
                return L
            if s[i] != ' ':
                L += 1
            i += 1
        return L
