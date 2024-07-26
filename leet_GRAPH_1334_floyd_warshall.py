class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:

        # Floyd-Warshall - DP

        W = [[1e20] * n for _ in range(n)]
        for u in range(n):
            W[u][u] = 0
        for u, v, w in edges:
            W[u][v] = w
            W[v][u] = w
        for d in range(n):
            for u in range(n):
                for v in range(n):
                    W[u][v] = min(W[u][v], W[u][d] + W[d][v])
        res = 1e20
        min_reachables = 1e20
        for u in range(n):
            reachables = 0
            for v in range(n):
                if W[u][v] <= distanceThreshold:
                    reachables += 1
            if min_reachables >= reachables:
                # print('u/', u, 'reachables/', reachables)
                min_reachables = reachables
                res = u
        assert res != 1e20
        return res
