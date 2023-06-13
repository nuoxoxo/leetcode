class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        D = defaultdict(lambda: 0)
        n = len(grid)
        cols = ['' for _ in range(n)]
        for line in grid:
            s = ' '.join([str(_) for _ in line])
            for i in range(n):
                cols[i] += ' ' + str(line[i])
            D[s] += 1
        res = 0
        for c in cols:
            c = c[1:]
            res += D[c]
        return res
