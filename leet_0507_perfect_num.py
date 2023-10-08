class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num < 2:
            return False
        res = 1
        sqr = num ** 0.5
        n = 2
        while n < sqr:
            if num % n != 0:
                n += 1
                continue
            res += n + num // n
            n += 1
        if num % n == 0 and int(sqr) >= n:
            res += n
        print(res, num)
        return res == num 
