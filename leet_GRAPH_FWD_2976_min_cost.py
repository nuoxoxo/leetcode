class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        return [
            Floyd_Warshall_DP,
            # Dijkstra,
        ][0](source, target, original, changed, cost)

def idx(char:str) -> int:
    return ord(char) - ord('a')

def Floyd_Warshall_DP(source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
    INF = int(1e9)
    W = [[INF] * 26 for _ in range(26)]
    for u, v, c in zip(original, changed, cost):
        U = idx(u)
        V = idx(v)
        W[U][V] = min(W[U][V], c)
    for inter in range(26):
        for u in range(26):
            for v in range(26):
                W[u][v] = min(W[u][v], W[u][inter] + W[inter][v])
    res = 0
    for u, v in zip(source, target):
        U = idx(u)
        V = idx(v)
        if U == V:
            continue
        if not W[U][V] < INF:
            return -1
        res += W[U][V]
    return res
        
def Dijkstra(source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
    W = defaultdict(list)
    for u, v, c in zip(original, changed, cost):
        U, V = idx(u), idx(v)
        W[U].append((c, V))
    INF = int(1e9)

    def dijkstra(src:int, des:int) -> int:
        SEEN = set()
        heap = [(0, src)]
        weights = [INF] * 26
        while heap:
            curr_cost, curr_node = heapq.heappop(heap)
            if curr_node == des:
                return curr_cost
            if curr_node not in SEEN:
                SEEN.add(curr_node)
                for next_cost, next_node in W[curr_node]:
                    tt_cost = curr_cost + next_cost
                    if tt_cost < weights[next_node]:
                        weights[next_node] = tt_cost
                        heapq.heappush(heap, (tt_cost, next_node))
        return INF

    res = 0
    cached = [[False] * 26 for _ in range(26)]
    caching = [[None] * 26 for _ in range(26)]
    for u, v in zip(source, target):
        if u == v:
            continue
        U,V = idx(u), idx(v)
        if cached[U][V]:
            res += caching[U][V]
        else:
            c = dijkstra(U,V)
            if c == INF:#assert c < INF
                return -1
            cached[U][V], caching[U][V] = True, c
            res += c
    return res

