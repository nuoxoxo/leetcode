class Solution:
    def numberOfMatches(self, n: int) -> int:
        r = 0
        while n != 0:
            # print(n)
            r += n // 2
            n = n // 2 + n % 2
            if n == 1:
                break
        return r
