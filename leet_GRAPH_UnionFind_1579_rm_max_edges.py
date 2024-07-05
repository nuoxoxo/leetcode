class UnionFind:
    def __init__(self, N):
        self.N = N
        self.parents = [_ for _ in range(N)]

    def _find(self, node):
        if self.parents[node] != node:
            self.parents[node] = self._find(self.parents[node])
        return self.parents[node]

    def _union(self, L, R):
        lunion = self._find(L)
        runion = self._find(R)
        if lunion != runion:
            self.parents[lunion] = runion

    def _is_connected(self, L, R):
        return self._find(L) == self._find(R)

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        A = UnionFind(n) # alice
        B = UnionFind(n) # bob
        res = 0
        for typ, u, v in edges:
            u -= 1
            v -= 1
            if typ != 3:
                continue
            if A._is_connected(u, v):
                res += 1
            else:
                A._union(u, v)
                B._union(u, v)
        for typ, u, v in edges:
            u -= 1
            v -= 1
            curr = None
            if typ == 1:
                curr = A
            elif typ == 2:
                curr = B
            else:
                continue
            assert curr
            if curr._is_connected(u, v):
                res += 1
            else:
                curr._union(u, v)
        for i in range(n):
            if not A._is_connected(0, i) or not B._is_connected(0, i):
                return -1
        return res
