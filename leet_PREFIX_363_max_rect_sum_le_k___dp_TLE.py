class Solution:
    def maxSumSubmatrix(self, grid: List[List[int]], k: int) -> int:
        r = len(grid)
        c = len(grid[0])
        dp = [[0] * c for _ in range(r + 1)]
        for i in range(r):
            for j in range(c):
                dp[i + 1][j] = dp[i][j] + grid[i][j]
        res = -1e9
        for i in range(r):
            for ii in range(i + 1, r + 1): # 2 vertical idx
                for j in range(c):
                    val = 0
                    for jj in range(j, c):
                        val += dp[ii][jj] - dp[i][jj]
                        if val == k:
                            return k
                        if val < k and val > res:
                            res = val
        return res


"""
[[1,0,1],[0,-2,3]]
2
[[1,0,1],[0,-2,3],[2,6,-6]]
2
[[1,0,1],[0,-2,3],[-10,-12,-1]]
2
[[2,2,-1]]
0
"""
