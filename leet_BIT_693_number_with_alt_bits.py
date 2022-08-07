class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        cmp = n % 2
        while n != 0:
            if cmp != n:
                return False
            cmp = 0 if cmp == 1 else 1
            n >>= 1
        return True
