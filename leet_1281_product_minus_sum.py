class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p = 1
        s = 0
        while n is not 0:
            k = n % 10
            p *= k
            s += k
            n //= 10
        return p - s
