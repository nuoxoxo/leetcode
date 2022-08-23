class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        arr = [''] * numRows
        n = len(s)
        r = 0
        for i in range(n):
            arr[r] += s[i]
            c = i // (numRows - 1)
            if c % 2 == 0:
                r += 1
            else:
                r -= 1
        res = ''
        for tmp in arr:
            res += tmp
        return res
