class Solution:
    def countDigits(self, num: int) -> int:
        r = 0
        tmp = num
        while tmp != 0:
            n = tmp % 10
            if num % n == 0:
                r += 1
            tmp //= 10
        return r
