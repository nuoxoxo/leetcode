class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.adj = [[] for _ in range(n)]
        for e in edges:
            node, dest, cost = e # from, to, dist
            self.adj[node].append((cost, dest))

    def addEdge(self, edge: List[int]) -> None:
        node, dest, cost = edge
        self.adj[node].append((cost, dest))

    def shortestPath(self, node1: int, node2: int) -> int:
        pq = [(0, node1)]
        D = [-1] * len(self.adj)
        D[node1] = 0
        while pq:
            dist, node = heapq.heappop(pq)
            if node == node2:
                return dist
            # loop and update
            # either uninitialized or a shorter path is found
            for cost, idx in self.adj[node]:
                if D[idx] == -1 or dist + cost < D[idx]:
                    D[idx] = dist + cost
                    heapq.heappush(pq, (D[idx], idx))

        return D[node2]


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
