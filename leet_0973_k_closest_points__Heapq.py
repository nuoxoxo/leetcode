class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        q = []
        for x, y in points:
            q.append([x ** 2 + y ** 2, x, y])
        heapq.heapify(q)
        while k > 0:
            d, x, y = heapq.heappop(q)
            res.append([x, y])
            k -= 1
        return res
