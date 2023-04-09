class Solution:
    def partitionString(self, s: str) -> int:
        S = set()
        res = 0
        for i in range(len(s)):
            if s[i] in  S:
                res += 1
                S.clear()
            S.add(s[i])
        return res + 1
