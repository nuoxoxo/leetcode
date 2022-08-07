class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        g = [[1] * n for _ in range(m)]
        dq = []
        dq.append([0, 0])
        while (len(dq) != 0):
            i, j = dq[0][0], dq[0][1]
            dq.pop(0)
            if i == m or j == n or g[i][j] > 1:
                continue
            if i > 0 and j > 0:
                g[i][j] = g[i - 1][j] + g[i][j - 1]
            dq.append([i + 1, j])
            dq.append([i, j + 1])
        return g[m - 1][n - 1]
