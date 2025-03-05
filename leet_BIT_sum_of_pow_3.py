class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        if n == 3 or n == 0:
            return True
        while n > 0:
            if n % 3 == 2:
                return False
            n //= 3
        return True
