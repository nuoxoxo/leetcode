class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        def dfs(r, c, x, y, prev):
            if x < 0 or x > r - 1 or y < 0 or y > c - 1 or matrix[x][y] <= prev:
                return 0
            L = dfs(r, c, x, y - 1, matrix[x][y])
            U = dfs(r, c, x - 1, y, matrix[x][y])
            R = dfs(r, c, x, y + 1, matrix[x][y])
            D = dfs(r, c, x + 1, y, matrix[x][y])
            return 1 + max(L, U, R, D)
        c = len(matrix[0])
        r = len(matrix)
        res = -1
        for x in range(r):
            for y in range(c):
                res = max(res, dfs(r, c, x, y ,-1))
        return res
