class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        N = len(grid)
        assert N == len(grid[0])
        R, C = [0] * N, [0] * N
        for r in range(N):
            for c in range(N):
                R[r] = max(R[r], grid[r][c])
                C[c] = max(C[c], grid[r][c])
        res = 0
        for r in range(N):
            for c in range(N):
                diff = min(R[r], C[c]) - grid[r][c]
                if diff > 0:
                    res += diff
        return res

