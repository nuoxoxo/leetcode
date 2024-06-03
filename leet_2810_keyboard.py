class Solution:
    def finalString(self, s: str) -> str:
        res = ''
        for r in range(len(s)):
            if s[r] == 'i':
                res = res[::-1]
            else:
                res += s[r]
        return res
