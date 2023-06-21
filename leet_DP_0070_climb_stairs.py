class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        E = defaultdict(lambda: 0)
        E[0] = 1;
        E[1] = 1;
        E[2] = 2;
        i = 2
        while i < n + 1:
            E[i] = E[i - 1] + E[i - 2]
            i += 1
        return E[n]
