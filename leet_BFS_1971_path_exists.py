class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        return [
            self.BFS,
        ][0](n, edges, source, destination)

    def BFS(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True
        END = set()
        END.add(source)
        Q = deque()
        Q.append(source)
        ADJ = defaultdict(list)
        # prepare an adjacency list
        for u, v in edges:
            ADJ[u].append(v)
            ADJ[v].append(u)
        while Q:
            u = Q.popleft()
            for v in ADJ[u]:
                if v == destination:
                    return True
                if v not in END:
                    Q.append(v)
                    END.add(v)
        return False

