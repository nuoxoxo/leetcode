class Solution:
    def largestLocal(self, g: List[List[int]]) -> List[List[int]]:
        def local_max(g: List[List[int]], r: int, c: int):
            res = -1
            for rr in range(r, r + 3):
                for cc in range(c, c + 3):
                    n = g[rr][cc]
                    res = n if res < n else res
            return res
        R = len(g) - 2
        C = len(g[0]) - 2
        res = [[0] * C for _ in range(R)]
        for r in range(R):
            for c in range(C):
                res[r][c] = local_max(g, r, c)
        return res


