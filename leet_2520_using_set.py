class Solution:
    def countDigits(self, num: int) -> int:
        S = set([int(_) for _ in str(num)])
        r = 0
        for n in S:
            if num % n == 0:
                r += str(num).count(str(n))
        return r
