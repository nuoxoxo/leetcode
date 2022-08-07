class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        def oneNeighbor(x, y, grid) -> int:
            if x == len(grid) or y == len(grid[0]) or x == -1 or y == -1:
                return 0
            return grid[x][y]
        def countNeighbors(x, y, grid) -> int:
            return oneNeighbor(x + 1, y, grid) + oneNeighbor(x - 1, y, grid) \
                + oneNeighbor(x, y + 1, grid) + oneNeighbor(x, y - 1, grid)
        c = len(grid[0])
        r = len(grid)
        tt = 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    tt += 4 - countNeighbors(i, j, grid)
        return tt
