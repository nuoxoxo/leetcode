class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        dx = [-1,0,0,1]
        dy = [0,-1,1,0]
        c = len(grid[0])
        r = len(grid)
        tt = 0
        for x in range(r):
            for y in range(c):
                if grid[x][y] == 1:
                    for n in range(4):
                        i, j = x + dx[n], y + dy[n]
                        if i == r or i < 0 or j == c or j < 0 or grid[i][j] == 0:
                            tt += 1
        return tt
