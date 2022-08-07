class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 1:
            return dividend
        s = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else -1
        n = abs(dividend) // abs(divisor)
        if n > 2147483647:
            return 2147483647
        return n * s
