class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        D = collections.defaultdict(int)
        N = len(s)
        L = 0
        res = 0
        for R,c in enumerate(s):
            D[c] += 1
            while D['a'] > 0 and D['b'] > 0 and D['c'] > 0:
                lc = s[L]
                D[lc] -= 1
                L += 1
                res += N - R
        return res

