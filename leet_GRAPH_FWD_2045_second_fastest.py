class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        ADJ = collections.defaultdict(list)
        for u, v in edges:
            u, v = u - 1, v - 1
            ADJ[u].append(v)
            ADJ[v].append(u)
        INF = int(1e20)
        heap = [(0, 0, 0)] # dist, node, index
        route1, route2 = [INF] * n, [INF] * n
        route1[0] = 0
        while heap:
            dist, node, _index = heapq.heappop(heap)
            if _index == 1 and node == n - 1: # end/
                return dist
            if _index == 0 and route1[node] > dist: continue
            if _index == 1 and route2[node] > dist: continue
            new_dist = dist
            if dist % (change * 2) < change: # Greenlight
                new_dist += time
            else: # Red
                #   new way
                waiting = change - (dist % change)
                new_dist += time + waiting
                #   initial soln
                # new_dist = (change * 2 + dist - 1) // (change * 2) * (change * 2) + time
            for _next in ADJ[node]:
                if new_dist < route1[_next]:
                    heapq.heappush(heap, (new_dist, _next, 0))
                    route2[_next] = route1[_next]
                    route1[_next] = new_dist
                elif route1[_next] < new_dist < route2[_next]:
                    heapq.heappush(heap, (new_dist, _next, 1))
                    route2[_next] = new_dist
        assert False
