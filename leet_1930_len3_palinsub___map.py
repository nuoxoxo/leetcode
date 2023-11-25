class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        D = {} #dict()
        # form of an item of D: char - [L-most index, R-most index]
        for i in range(len(s)):
            c = s[i]
            if c in D:
                D[c][1] = i
            else:
                D[c] = [i, -1]
        res = 0
        for k, v in D.items():
            l, r = v[0], v[1]
            # print(k, v, l, r)
            if r == -1:
                continue # char is unique
            S = set()
            for i in range(l + 1, r):
                S.add(s[i])
            res += len(S)
        return res
