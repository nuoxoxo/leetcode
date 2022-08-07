class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0
        c = 0
        while num != 0:
            c += 1
            if num % 2 == 1:
                num -= 1
            else:
                num //= 2
        return c
