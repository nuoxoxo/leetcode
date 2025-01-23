class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        R,C = len(grid), len(grid[0])
        dist = [[10**20 for _ in range(C)] for _ in range(R)]
        dist[0][0] = 0
        D = ((1,0,1),(2,0,-1),(3,1,0),(4,-1,0))
        Q = collections.deque([(0,0)])
        while Q:
            r,c = Q.popleft()#pop(0)
            for d,dr,dc in D:
                rr,cc = r + dr, c + dc
                if -1<rr<R and -1<cc<C:
                    cost = 0 if d == grid[r][c] else 1
                    tt = cost + dist[r][c]
                    if dist[rr][cc] > tt:
                        dist[rr][cc] = tt
                        if cost:
                            Q.append((rr,cc))
                        else:
                            Q.appendleft((rr,cc))#Q = [(rr,cc)] + Q
        return dist[R - 1][C - 1]
