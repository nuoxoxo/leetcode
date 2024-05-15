class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        N = len(grid)
        assert len(grid[0]) == N
        Q = deque()
        safe = [[10 ** 20] * N for _ in range(N)]
        seen = [[False] * N for _ in range(N)]
        for r in range(N):
            for c in range(N):
                if grid[r][c] == 1:
                    Q.append((r, c, 0))
                    safe[r][c] = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        while Q:
            r, c, dis = Q.popleft()
            for i in range(4):
                rr = r + dr[i]
                cc = c + dc[i]
                if not -1 < rr < N or not -1 < cc < N or safe[rr][cc] != 10 ** 20:
                    continue
                # print(rr, cc)
                safe[rr][cc] = dis + 1
                Q.append((rr, cc, dis + 1))
        seen[0][0] = True
        assert not Q
        Q.append((0, 0, safe[0][0]))
        while Q:
            r, c, dis = Q.popleft()
            if r == c == N - 1:
                return dis
            for i in range(4):
                rr = r + dr[i]
                cc = c + dc[i]
                if not -1 < rr < N or not -1 < cc < N or seen[rr][cc]:
                    continue
                # print(rr, cc)
                seen[rr][cc] = True
                if dis > safe[rr][cc]:
                    Q.append((rr, cc, safe[rr][cc]))
                else:
                    Q.appendleft((rr, cc, dis))
        assert False

