class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        R,C = len(grid),len(grid[0])
        sumR,sumC = list(map(sum,grid)),list(map(sum,zip(*grid)))
        res = 0
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1 and sumR[r] + sumC[c] > 2:
                    res += 1
        return res

