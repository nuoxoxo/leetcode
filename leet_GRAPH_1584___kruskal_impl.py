class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def Man(L, R):
            return abs(L[0] - R[0]) + abs(L[1] - R[1])
        pq = []
        p0 = points.pop(0)
        res = 0
        for p in points:
            dist = Man(p0, p)
            pq.append([dist, p])
        pq.sort(key=lambda x: x[0])
        while pq:
            dist, coor = pq.pop(0)
            res += dist
            for i in range(len(pq)):
                pq[i][0] = min(pq[i][0], Man(pq[i][1], coor))
            pq.sort(key=lambda x: x[0])
        return res
