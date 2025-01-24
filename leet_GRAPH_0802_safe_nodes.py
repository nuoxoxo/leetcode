class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        N = len(graph)
        parentsof = [[] for _ in range(N)]
        childrensizeof = [-1] * N
        Q = collections.deque()
        terms = []
        for node,children in enumerate(graph):
            for child in children:
                parentsof[child].append(node)
            size = len(children)
            childrensizeof[node] = size
            if size == 0: # means a single lone terminal
                terms.append(node)
                Q.append(node)
        while Q:
            node = Q.popleft()
            for parent in parentsof[node]:
                childrensizeof[parent] -= 1
                if childrensizeof[parent] == 0:
                    terms.append(parent)
                    Q.append(parent)
        return sorted(terms)



