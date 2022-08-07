class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        c = len(grid[0])
        r = len(grid)
        area = r * c
        k %= area
        if k == 0:
            return grid
        v = [ [ None for _ in range(c) ] for _ in range(r) ]
        for i in range(r):
            for j in range(c):
                index = (i * c + j + k) % area
                di = index // c
                dj = index % c
                v[di][dj] = grid[i][j]
        return v
