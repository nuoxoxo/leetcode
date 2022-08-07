class Solution:
    def numberOfSteps(self, num: int) -> int:
        def solve(n: int, c: int) -> int:
            if n == 0:
                return c
            if n % 2 == 0:
                return solve(n / 2, c + 1)
            return solve(n - 1, c + 1)
        return solve(num, 0)
