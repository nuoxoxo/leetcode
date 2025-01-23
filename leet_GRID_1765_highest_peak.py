class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        Q = collections.deque()
        R,C = len(isWater), len(isWater[0])
        for r in range(R):
            for c in range(C):
                if isWater[r][c]:
                    Q.append((r,c))
                    isWater[r][c] = 0
                else:
                    isWater[r][c] = -1
        for l in isWater:print(l)
        h = 1
        D = ((0,-1),(1,0),(-1,0),(0,1))
        while 42:
            N = len(Q)
            for i in range(N):
                r,c = Q.popleft()
                for dr,dc in D:
                    rr,cc = r + dr, c + dc
                    if -1<rr<R and -1<cc<C and isWater[rr][cc] == -1:
                        isWater[rr][cc] = h
                        Q.append((rr,cc))
            if not Q:
                break
            h += 1
        return isWater

