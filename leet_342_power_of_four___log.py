class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n < 1:
            return False
        r = log2(n) / 2
        if ceil(r) == floor(r):
            return True
        return False
