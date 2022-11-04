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
        for i in range(r): # leftmost & rightmost col
            DFS(i, 0, r, c, pac, h[i][0])
            DFS(i, c - 1, r, c, alt, h[i][c - 1])
        for i in range(c): # top & bottom row
            DFS(0, i, r, c, pac, h[0][i])
            DFS(r - 1, i, r, c, alt, h[r - 1][i])
        # print(pac)
        # print(alt)
        res = []
        for r in range(R):
            for c in range(C):
                if (r, c) in pac and (r, c) in alt:
                    res.append([r, c])
        return res
