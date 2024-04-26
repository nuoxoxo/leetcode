class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        """
        15 - 157,159
        16 - 167,168
        24 - 248,249
        26 - 267,268
        34 - 348,349
        35 - 357,359
        """
        return [
            self.nCubed,
        ][0](grid)

    """
    def faster_dp(self, grid: List[List[int]]) -> int:

        INF = 10 ** 20
        N = len(grid)
        R, C = N, N
        dp = [[INF for _ in range(C)] for _ in range(R)]
        for c in range(C):
            dp[0][c] = grid[0][c]
        for r in range(1, R):
    """


    def nCubed(self, grid: List[List[int]]) -> int:

        # Slow: O(n^3)
        INF = 10 ** 20
        N = len(grid)
        R, C = N, N
        dp = [[INF for _ in range(C)] for _ in range(R)]
        for c in range(C):
            dp[0][c] = grid[0][c]
        for r in range(1, R):
            for c in range(C):
                for idx in range(C):
                    if idx == c:
                        continue
                    temp = dp[r - 1][idx] + grid[r][c]
                    dp[r][c] = min(dp[r][c], temp)
        return min(dp[-1])
        
