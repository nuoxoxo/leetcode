class Solution:
    
    from collections import deque 
    
    def shortestPathBinaryMatrix(self, g: List[List[int]]) -> int:
        n = len(g)
        if n < 2:
            return 1
        if g[0][0] != 0 or g[n - 1][n - 1] != 0:
            return -1
        di = [-1,-1,-1, 0,0, 1,1,1]
        dj = [-1, 0, 1,-1,1,-1,0,1]
        dq = [(0, 0)]
        g[0][0] = 1
        res = 0
        while True:
            size = len(dq)
            if size == 0:
                break
            res += 1
            for _ in range(size):
                p = dq.pop(0)
                i = p[0]
                j = p[1]
                if i == n - 1 and j == n - 1:
                    return res
                for k in range(8):
                    x, y = i + di[k], j + dj[k]
                    if -1 < x < n and -1 < y < n and g[x][y] == 0:
                        dq.append((x, y))
                        g[x][y] = 1
        return -1
