class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        R,C = len(grid), len(grid[0])
        topsum = sum(grid[0])
        bottomsum = sum(grid[-1])
 
        topcurr = grid[0][0]
        bottomcurr = bottomsum
 
        score = max(topsum - topcurr, bottomsum - bottomcurr)
        res = score
        for c in range(1,C):
            topcurr += grid[0][c]
            bottomcurr -= grid[1][c - 1]
            score = max(topsum - topcurr, bottomsum - bottomcurr)
            res = min(res,score)
        return res
