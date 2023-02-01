class Solution:
    def gcdOfStrings(self, s1: str, s2: str) -> str:
        if s1 + s2 != s2 + s1:
            return ''
        g = math.gcd(len(s1), len(s2))
        res = ''
        for i in range(g):
            res += s1[i]
        return res
