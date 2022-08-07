class Solution:
    def divide(self, dd: int, dv: int) -> int:
        if dv == 1:
            return dd
        d, v = abs(dd), abs(dv)
        res = 0
        sign = 1 if (dd > 0 and dv > 0) or (dd < 0 and dv < 0) else -1
        while d >= v:
            fac = 1
            tmp = v
            while d >= tmp:
                res += fac
                d -= tmp
                fac <<= 1
                tmp <<= 1
        if res > 2147483647:
            return 2147483647
        return res * sign
