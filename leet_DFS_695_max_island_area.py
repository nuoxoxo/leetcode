class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        c = len(grid[0])
        r = len(grid)
        res = 0
        x = 0
        while x < r:
            y = 0
            while y < c:
                if grid[x][y] == 1:
                    tmp = self.dfs(grid, x, y)
                    res = max(res, tmp)
                y += 1
            x += 1
        return res

    def dfs(self, grid: List[List[int]], x: int, y: int) -> int:
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]) or grid[x][y] ^ 1:
            return 0
        grid[x][y] = 0
        l = self.dfs(grid, x - 1, y)
        u = self.dfs(grid, x , y - 1)
        r = self.dfs(grid, x + 1, y)
        d = self.dfs(grid, x, y + 1)
        return l + u + r + d + 1
