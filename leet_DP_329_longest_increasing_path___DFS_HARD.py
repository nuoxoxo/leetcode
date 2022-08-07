class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        c = len(matrix[0])
        r = len(matrix)
        dp = [ [-1] * c for _ in range(r) ]
        def dfs(x, y, prev):
            if x < 0 or x > r - 1 or y < 0 or y > c - 1 or matrix[x][y] <= prev:
                return 0
            if dp[x][y] != -1:
                return dp[x][y]
            L = dfs(x, y - 1, matrix[x][y])
            U = dfs(x - 1, y, matrix[x][y])
            R = dfs(x, y + 1, matrix[x][y])
            D = dfs(x + 1, y, matrix[x][y])
            dp[x][y] = max(L, U, R, D) + 1
            return dp[x][y]
        res = -1
        for x in range(r):
            for y in range(c):
                res = max(res, dfs(x, y ,-1))
        return res
