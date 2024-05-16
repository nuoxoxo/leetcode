class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)
        res = [] # [][]node
        candidate = [] # []node

        def backtrack (node) -> None:
            candidate.append(node) # try
            # print(res)
            if node == N - 1:
                # end reached
                res.append(candidate[:])
                # res.append(candidate)
                #   👆 bugfix - should be a copy - cand[:]
            else:
                # recurse on all next/adj nodes
                for nxt in graph[node]:
                    backtrack(nxt)
            candidate.pop()

        backtrack(0)
        return res

