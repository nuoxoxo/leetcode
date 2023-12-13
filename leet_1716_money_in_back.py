class Solution:
    def totalMoney(self, n: int) -> int:
        res = 0
        m, w, lim = 1, 1, 7 # money, weekcount, end of a week (7,8,9...)
        while n > 0:
            if m > lim:
                w += 1
                lim += 1
                m = w
            res += m
            m += 1
            n -= 1
        return res
