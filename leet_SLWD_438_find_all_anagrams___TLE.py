class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ls = len(s)
        lp = len(p)
        a = ord('a')
        E = [0] * 26
        if ls < lp:
            return []
        res = []
        for i in range(lp):
            E[ord(p[i]) - a ] += 1
        for i in range(ls - lp + 1):
            tmp = [0] * 26
            for j in range(lp):
                tmp[ord(s[ i + j ]) - a] += 1
            if E == tmp:
                res.append(i)
        return res
