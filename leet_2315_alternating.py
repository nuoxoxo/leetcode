class Solution:
    def countAsterisks(self, s: str) -> int:
        res = 0
        incl = True
        for c in s:
            if c == '|':
                incl = not incl
            if spot and c == '*':
                res += 1
        return res

