class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        cols = len(grid[0])
        rows = len(grid)
        r1 = []
        r0 = []
        c1 = [0] * cols
        c0 = [0] * cols 
        for r in grid:
            r1.append(r.count(1))
            r0.append(r.count(0))
            for i in range(len(r)):
                if r[i] == 1:
                    c1[i] += 1
                else:
                    c0[i] += 1
        # print(r1, r0, c1, c0)
        res = [[0 for _ in range(cols)] for _ in range(rows)]
        for r in range(rows):
            for c in range(cols):
                res[r][c] = r1[r] - r0[r] + c1[c] - c0[c]
        return res

