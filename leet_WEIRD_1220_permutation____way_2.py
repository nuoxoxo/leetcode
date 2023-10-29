class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a, e, i, o, u = 1, 1, 1, 1, 1
        mod = int(1e9) + 7
        for _ in range(n - 1):
            aa = (e + i + u) % mod
            ee = (a + i) % mod
            ii = (e + o) % mod
            oo = (i) % mod
            uu = (i + o) % mod
            a, e, i, o, u = aa, ee, ii, oo, uu
        return ( a + e + i + o + u ) % mod
"""
2nd way to think about it

a   -   e, i, u
e   -   a, i
i   -   e, o
o   -   i
u   -   i, o

"""
