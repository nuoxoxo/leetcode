class Solution:
    def uniquePathsWithObstacles(self, G: List[List[int]]) -> int:
        c = len(G[0])
        r = len(G)
        g = [[0] * c for _ in range(r)]
        dr = [(1, 0), (0, 1)]
        dq = []
        if G[0][0] == 0:
            g[0][0] = 1
        else:
            g[0][0] = 0
        dq.append((0, 0))
        while len(dq) != 0:
            p = dq.pop(0)
            i = p[0]
            j = p[1]
            val = g[i][j]
            for d in dr:
                di = d[0] + i
                dj = d[1] + j
                if di == r or dj == c or G[di][dj] == 1:
                    continue
                if g[di][dj] == 0:
                    dq.append((di, dj))
                g[di][dj] += val
        return g[r - 1][c - 1]
