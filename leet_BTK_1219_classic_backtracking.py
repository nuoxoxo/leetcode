class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        def backtrack(r, c, curr) -> int:
            if not -1 < r < R or not -1 < c < C or grid[r][c] == 0:
                return curr
            curr += grid[r][c]
            temp = grid[r][c]
            grid[r][c] = 0
            res = max(
                backtrack(r - 1, c, curr),
                backtrack(r + 1, c, curr),
                backtrack(r, c - 1, curr),
                backtrack(r, c + 1, curr),
            )
            grid[r][c] = temp
            return res
        res = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 0:continue
                res = max(res, backtrack(r, c, 0))
        return res

