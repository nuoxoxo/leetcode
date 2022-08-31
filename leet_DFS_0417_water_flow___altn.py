class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        def DFS(r, c, R, C, visited, lastpos):
            if r < 0 or c < 0 or r > R - 1 or c > C - 1 or \
                visited[r][c] or h[r][c] < lastpos:
                    return
            visited[r][c] = True
            DFS(r + 1, c, R, C, visited, h[r][c])
            DFS(r - 1, c, R, C, visited, h[r][c])
            DFS(r, c + 1, R, C, visited, h[r][c])
            DFS(r, c - 1, R, C, visited, h[r][c])
        R = len(h)
        C = len(h[0])
        pac = [[False for _ in range(C)] for _ in range(R)]
        alt = [[False for _ in range(C)] for _ in range(R)]
        # print(pac, alt)
        for r in range(R):
            DFS(r, 0,       R, C, pac, h[r][0])
            DFS(r, C - 1,   R, C, alt, h[r][C - 1])
        # print(pac, alt)
        for c in range(C):
            DFS(0, c,       R, C, pac, h[0][c])
            DFS(R - 1, c,   R, C, alt, h[R - 1][c])
        res = []
        for r in range(R):
            for c in range(C):
                if pac[r][c] and alt[r][c]:
                    res.append([r, c])
        return res
