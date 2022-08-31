class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        def DFS(i, j, r, c, visited, lastpos) :
            if i < 0 or j < 0 or i > r - 1 or j > c - 1 or \
                (i, j) in visited or h[i][j] < lastpos:
                    return
            visited.add((i, j))
            DFS(i + 1, j, r, c, visited, h[i][j])
            DFS(i - 1, j, r, c, visited, h[i][j])
            DFS(i, j + 1, r, c, visited, h[i][j])
            DFS(i, j - 1, r, c, visited, h[i][j])
        r = len(h)
        c = len(h[0])
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
        for i in range(r):
            for j in range(c):
                if (i, j) in pac and (i, j) in alt:
                    res.append([i, j])
        return res
