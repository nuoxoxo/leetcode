class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        def DFS(r, c, R, C, visited, lastpos) :
            if r < 0 or c < 0 or r > R - 1 or c > C - 1 or \
                (r, c) in visited or h[r][c] < lastpos:
                    return
            visited.add((r, c))
            DFS(r + 1, c, R, C, visited, h[r][c])
            DFS(r - 1, c, R, C, visited, h[r][c])
            DFS(r, c + 1, R, C, visited, h[r][c])
            DFS(r, c - 1, R, C, visited, h[r][c])
        R, C = len(h), len(h[0])
        pac = set() # two visited sets
        alt = set()
        for r in range(R):
            DFS(r, 0, R, C, pac, h[r][0]) # start from left col ie. [i][0]
            DFS(r, C - 1, R, C, alt, h[r][C - 1])
        for c in range(C):
            DFS(0, c, R, C, pac, h[0][c])
            DFS(R - 1, c, R, C, alt, h[R - 1][c])
        # print(pac)
        # print(alt)
        res = []
        for r in range(R):
            for c in range(C):
                if (r, c) in pac and (r, c) in alt:
                    res.append([r, c])
        return res
