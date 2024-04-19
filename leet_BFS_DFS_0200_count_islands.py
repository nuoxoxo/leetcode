class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        return [
            self.Floodfill,
        ][0](grid)

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

