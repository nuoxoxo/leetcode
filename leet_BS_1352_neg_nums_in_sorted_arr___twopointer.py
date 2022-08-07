class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res = 0
        r = len(grid)
        c = len(grid[0])
        i = 0
        j = c - 1
        while i < r and j > -1:
            if grid[i][j] < 0:
                res += r - i
                j -= 1
            else:
                i += 1
        return res
