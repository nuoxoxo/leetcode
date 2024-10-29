class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        DP = [None] * R
        for r in range(R):
            DP[r] = [False] * C
            DP[r][0] = True
        res = 0
        for c in range(1, C):
            cc = c - 1
            for r in range(R):
                if DP[r][cc] and grid[r][cc] < grid[r][c] or \
                r > 0 and DP[r - 1][cc] and grid[r - 1][cc] < grid[r][c] or \
                r < R - 1 and DP[r + 1][cc] and grid[r + 1][cc] < grid[r][c]:
                    DP[r][c] = True
                if DP[r][c]: res = c
        # for dp in DP:print(dp)
        return res
