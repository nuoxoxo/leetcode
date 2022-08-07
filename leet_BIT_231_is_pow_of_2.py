# Faster solve

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while n != 1:
            if n < 1:
                return False
            n /= 2
        return True

# Initial solve

"""
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 1:
            return False
        if 2 ** 32 % n == 0:
            return True
        return False
"""
