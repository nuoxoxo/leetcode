class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def manh_dist(x, y):
            return abs(x[0] - y[0]) + abs(x[1] - y[1])
        pq = []
        tt = 0
        for i in range(1, len(points)):
            heapq.heappush(
                pq,
                [ manh_dist(points[0], points[i]), points[i] ]
            )
        while pq:
            temp = heapq.heappop(pq)
            tt += temp[0]
            for dist in pq:
                dist[0] = min(dist[0], manh_dist(temp[1], dist[1]))
            heapq.heapify(pq)
        return tt
