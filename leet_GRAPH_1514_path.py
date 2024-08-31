class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        ADJ = collections.defaultdict(list)
        used = [False] * n
        bestprob = [0.0] * n

        for (u, v), p in zip(edges, succProb):
            ADJ[u].append((v, p))
            ADJ[v].append((u, p))
        Q = [(-1., start_node)]
        heapq.heapify(Q)
        bestprob[start_node] = 1.0
        while Q:
            prob, node = heapq.heappop(Q)
            prob *= -1.
            if used[node]:
                continue
            used[node] = True
            for v, oldprob in ADJ[node]:
                newprob = prob * oldprob
                if bestprob[v] >= newprob:
                    continue
                heapq.heappush(Q, (-newprob, v))
                bestprob[v] = newprob
        return bestprob[end_node]
