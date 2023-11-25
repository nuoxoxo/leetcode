class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss = ''
        for c in s:
            if c.isalnum():
                ss += c.lower()
        L = len(ss)
        for i in range(L // 2):
            if ss[i] != ss[L - 1 - i]:
                return False
        return True
