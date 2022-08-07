class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = isqrt(c)
        while a <= b:
            p = a * a + b * b
            if p == c:
                return True
            if p < c:
                a += 1
            else:
                b -= 1
        return False
            
