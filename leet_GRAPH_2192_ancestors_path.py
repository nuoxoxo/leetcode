class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ance = [[] for _ in range(n)]
        for src, des in edges:
            ance[des].append(src)
        def DFS(node: int, seen: set, parents: set) -> None:
            if node not in seen:
                seen.add(node)
                parents.add(node)
                for parent in ance[node]:
                    if parent not in seen:
                        DFS(parent, seen, parents)
        res = [[] for _ in range(n)]
        for node in range(n):
            seen = set()
            path = set()
            for parent in ance[node]:
                if parent not in seen:
                    DFS(parent, seen, path)
            res[node] = sorted(list(path))
        return res

