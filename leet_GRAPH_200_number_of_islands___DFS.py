class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        c = len(grid[0])
        r = len(grid)
        res = 0

        def dfs(grid: List[List[str]], x: int, y: int, r: int, c: int):
            if x < 0 or x > r - 1 or y < 0 or y > c - 1 or grid[x][y] != '1':
                return
            grid[x][y] = ' '
            dfs(grid, x + 1, y, r, c);
            dfs(grid, x - 1, y, r, c);
            dfs(grid, x, y + 1, r, c);
            dfs(grid, x, y - 1, r, c);

        for x in range(r):
            for y in range(c):
                if grid[x][y] == '1':
                    res += 1
                    dfs(grid, x, y, r, c)
        return res

    
