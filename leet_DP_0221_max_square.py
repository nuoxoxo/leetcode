class Solution:
    def maximalSquare(self, m: List[List[str]]) -> int:
        if len(m) < 1:
            return 0
        R = len(m)
        C = len(m[0])
        a = 0
        dp = [[0] * (C + 1) for _ in range(R + 1)]
        for r in range(R):
            for c in range(C):
                if m[r][c] == '1':
                    dp[r + 1][c + 1] = min(dp[r][c], dp[r + 1][c], dp[r][c + 1]) + 1
                    a = max(a, dp[r + 1][c + 1])
        return a ** 2
