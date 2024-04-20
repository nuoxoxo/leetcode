class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        return [
            self.Floodfill,
            self.BFS,
        ][0](grid)

    def BFS(self, G: List[List[str]]) -> int:
        R, C = len(G), len(G[0])
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        seen = set()
        Q = deque()
        res = 0
        for r in range(R):
            for c in range(C):
                if G[r][c] == '1' and (r, c) not in seen:
                    res += 1
                    seen.add( (r, c) )
                    Q.append( (r, c) )

                    # Floodfill using BFS
                    while Q:
                        node = Q.popleft()
                        for i in range(4):
                            rr = node[0] + dr[i]
                            cc = node[1] + dc[i]
                            if -1 < rr < R and -1 < cc < C and \
                                G[rr][cc] == '1' and (rr, cc) not in seen:
                                Q.append( (rr, cc) )
                                seen.add( (rr, cc) )
        return res

    def Floodfill(self, G: List[List[str]]) -> int:
        R, C = len(G), len(G[0])
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        def flood(G: List[List[str]], r: int, c: int) -> None:
            if not -1 < r < R or not -1 < c < C or G[r][c] != '1':
                return
            G[r][c] = '0'
            for i in range(4):
                flood(G, r + dr[i], c + dc[i])
        res = 0
        for r in range(R):
            for c in range(C):
                if G[r][c] == '1':
                    res += 1
                    flood(G, r, c)
        return res

