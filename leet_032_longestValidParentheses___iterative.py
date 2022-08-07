class Solution:
    def longestValidParentheses(self, s: str) -> int:
        o = c = res = 0
        for ch in s:
            if ch == '(':
                o += 1
            else:
                c += 1
            if o < c:
                o = c = 0
            elif o == c:
                res = max(o + c, res)
        s = s[::-1]
        o = c = 0
        for ch in s:
            if ch == '(':
                o += 1
            else:
                c += 1
            if o > c:
                o = c = 0
            elif o == c:
                res = max(o + c, res)
        return res
