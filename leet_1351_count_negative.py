class Solution:
    def countNegatives(self, g: List[List[int]]) -> int:
        R = len(g)
        C = len(g[0])
        r = 0
        c = C - 1
        res = 0
        while r < R and c > -1:
            if g[r][c] < 0:
                res += R - r
                c -= 1
            else:
                r += 1
        return res
