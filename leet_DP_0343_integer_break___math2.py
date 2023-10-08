class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        quo = n // 3
        rem = n % 3
        if rem == 2:
            return 3 ** quo * 2
        if rem == 1:
            return 3 ** (quo - 1) * 4
        return 3 ** quo 


