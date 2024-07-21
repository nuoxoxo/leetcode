class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def Toposort(conditions: List[List[int]]) -> List[int]:
            goingto = {}
            goingto = collections.defaultdict(list)
            indegree = [0] * k
            # Toposort 1/
            #   - for each vertex, count its incoming edges ie. in-degree
            for src, des in conditions:
                src -= 1
                des -= 1
                indegree[des] += 1
                goingto[src].append(des)
            # Toposort 2/
            # Toposort 2/
            #   - add all 0-indegree vertices in queue
            ordering = []
            Q = deque()
            for vertice in range(k):
                if indegree[vertice] == 0:
                    Q.append(vertice)
            # Toposort 3/
            #   - pop a vertice, ie. this vertice has the fewest incoming nodes/in-degrees
            #   - add vertice to the left of ordering
            #   - for every next-node of the vertice
            #       - decrease it indegree
            #       - add this next-node to queue if its indegree drop to 0
            while Q:
                vertice = Q.popleft()
                ordering.append(vertice)
                for _next in goingto[vertice]:
                    indegree[_next] -= 1
                    if indegree[_next] == 0:
                        Q.append(_next)
            assert len(ordering) == k
            return ordering
        try:
            Rows = Toposort(rowConditions)
            Cols = Toposort(colConditions)
        except:
            return []
        res = [[0] * k for _ in range(k)]
        for vertice in range(k):
            rindex = Rows.index(vertice)
            cindex = Cols.index(vertice)
            res[rindex][cindex] = vertice + 1
        return res

                
                

