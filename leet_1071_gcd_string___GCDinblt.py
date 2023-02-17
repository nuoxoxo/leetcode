class Solution:
    def gcdOfStrings(self, s1: str, s2: str) -> str:
        def GCD(a: int, b: int) -> int:
            res = min(a, b)
            while res > 0:
                if a % res == 0 and b % res == 0:
                    break
                res -= 1
            return res
        if s1 + s2 != s2 + s1:
            return ''
        size1, size2 = len(s1), len(s2)
        S = s1 if size1 > size2 else s2
        size = math.gcd(size1, size2)
        res = ''
        for i in range(size):
            res += S[i]
        return res
