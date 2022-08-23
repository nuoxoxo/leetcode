class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = ''
        n = len(s)
        for i in range(numRows):
            r = 2 * (numRows - 1)
            for c in range(i, n, r):
                res += s[c]
                in_between = r + c - i * 2
                if 0 < i < numRows - 1 and in_between < n:
                    res += s[in_between]
        return res
