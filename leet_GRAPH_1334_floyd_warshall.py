class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        return [
            Floyd_Warshall_DP, # O(N x N x N)
            # Dijkstra, # O(N^2)
        ][0](n, edges, distanceThreshold)

# O(N x N)
def Dijkstra(n: int, edges: List[List[int]], distanceThreshold: int) -> int:
    W = defaultdict(list)
    for u, v, w in edges:
        W[u].append((w, v))
        W[v].append((w, u))
    def dijkstra_get_total_reachables(src: int):
        seen = set()
        heap = []
        heapify(heap)
        heapq.heappush(heap, (0, src))
        while heap:
            curr_w, curr_node = heapq.heappop(heap)
            if curr_node not in seen:
                seen.add(curr_node)
                for next_w, next_node in W[curr_node]:
                    tt_w = curr_w + next_w
                    if tt_w <= distanceThreshold:
                        heapq.heappush(heap, (tt_w, next_node))
        return len(seen) - 1
    res = 42
    min_reachables = n
    for u in range(n):
        reachables = dijkstra_get_total_reachables(u)
        if min_reachables >= reachables:
            min_reachables = reachables
            res = u
    return res

# O(N x N x N)
def Floyd_Warshall_DP(n: int, edges: List[List[int]], distanceThreshold: int) -> int:
    INF = int(1e6)
    W = [[INF] * n for _ in range(n)]
    for u in range(n):
        W[u][u] = 0
    for u, v, w in edges:
        W[u][v] = w
        W[v][u] = w
    for k in range(n):
        for u in range(n):
            for v in range(n):
                W[u][v] = min(W[u][v], W[u][k] + W[k][v])
    res = 42
    min_reachable = n
    for u in range(n):
        reachables = 0
        for v in range(n):
            if W[u][v] <= distanceThreshold:
                reachables += 1
        if min_reachable >= reachables:
            min_reachable = reachables
            res = u
    return res


        
