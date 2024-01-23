class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        return [
            self.Solution_DFS_Floodfill,
        ][ random.randint(0,0) ]( grid )

    def Solution_DFS_Floodfill (self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        if R == 0 or C == 0:
            return 0
        dr = [-1,0,1,0]
        dc = [0,-1,0,1]
        def DFS_Floodfill (r, c) -> None:
            if -1 < r < R and -1 < c < C and grid[r][c] == 0:
                grid[r][c] = 1
                for rr, cc in zip(dr, dc):
                    DFS_Floodfill (r + rr, c + cc)
        res = 0
        for c in range(C): # top & bottoml edges
            DFS_Floodfill(0, c)
            DFS_Floodfill(R - 1, c)
        for r in range(R): # left & right edges
            DFS_Floodfill(r, 0)
            DFS_Floodfill(r, C - 1)
        for r in range(1, R - 1): # 
            for c in range(1, C - 1):
                if grid[r][c] == 0:
                    res += 1
                    DFS_Floodfill(r, c)
        return res
