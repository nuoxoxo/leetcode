class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        return [
            self.MonotonicStack
        ][0]( num, k )

    def MonotonicStack(self, num, str, k: int) -> str:
        N = len(num)
        if not k < N:
            return '0'
        res = []
        for c in num:
            while res and res[-1] > c and k > 0:
                res.pop()
                k -= 1
            res.append(c)
        while res and k > 0:
            res.pop()
            k -= 1
        if not res:
            return '0'
        L = 0 # end index of left zero group
        while L < len(res) and res[L] == '0':
            L += 1
        res = res[L:]
        if not res:
            return '0'
        return ''.join(res)
"""
"1432219" - 3
"1219"

"10200" - 1
"200"
"""
