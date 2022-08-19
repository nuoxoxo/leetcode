class Solution:
    def minimumSum(self, num: int) -> int:
        t = []
        while num > 0:
            t.append(num % 10)
            num //= 10
        t.sort()
        return 10 * (t[0] + t[1]) + t[2] + t[3]
